在计算机系统中有一种说法，任何系统问题都可以用某种程度的抽象方法来解决。Lazy allocation实验中提供了一个例子。这个实验探索了另一个例子：写时复制分支（copy-on write fork）。

跟着提示一步一步来

**(1).** 在***kernel/riscv.h***中选取PTE中的保留位定义标记一个页面是否为COW Fork页面的标志位

```cpp
// 记录应用了COW策略后fork的页面
#define PTE_COW (1L << 8)
```

**(2).** 在***kalloc.c***中进行如下修改

- 定义引用计数的全局变量`ref`，其中包含了一个自旋锁和一个引用计数数组，由于`ref`是全局变量，会被自动初始化为全0。
    
    这里使用自旋锁是考虑到这种情况：进程P1和P2共用内存M，M引用计数为2，此时CPU1要执行`fork`产生P1的子进程，CPU2要终止P2，那么假设两个CPU同时读取引用计数为2，执行完成后CPU1中保存的引用计数为3，CPU2保存的计数为1，那么后赋值的语句会覆盖掉先赋值的语句，从而产生错误
    

```cpp
struct ref_stru {
  struct spinlock lock;
  int cnt[PHYSTOP / PGSIZE];  // 引用计数
} ref;
```

- 在`kinit`中初始化`ref`的自旋锁

对于上下文操作，进程要一直等待，自旋锁有这个特性。

```cpp
void
kinit()
{
  initlock(&kmem.lock, "kmem");
  initlock(&ref.lock, "ref");
  freerange(end, (void*)PHYSTOP);
}
```

- 修改`kalloc`和`kfree`函数，在`kalloc`中初始化内存引用计数为1，在`kfree`函数中对内存引用计数减1，如果引用计数为0时才真正删除

```cpp
void
kfree(void *pa)
{
  struct run *r;

  if(((uint64)pa % PGSIZE) != 0 || (char*)pa < end || (uint64)pa >= PHYSTOP)
    panic("kfree");

  // 只有当引用计数为0了才回收空间
  // 否则只是将引用计数减1
  acquire(&ref.lock);
  if(--ref.cnt[(uint64)pa / PGSIZE] == 0) {
    release(&ref.lock);

    r = (struct run*)pa;

    // Fill with junk to catch dangling refs.
    memset(pa, 1, PGSIZE);

    acquire(&kmem.lock);
    r->next = kmem.freelist;
    kmem.freelist = r;
    release(&kmem.lock);
  } else {
    release(&ref.lock);
  }
}

void *
kalloc(void)
{
  struct run *r;

  acquire(&kmem.lock);
  r = kmem.freelist;
  if(r) {
    kmem.freelist = r->next;
    acquire(&ref.lock);
    ref.cnt[(uint64)r / PGSIZE] = 1;  // 将引用计数初始化为1
    release(&ref.lock);
  }
  release(&kmem.lock);

  if(r)
    memset((char*)r, 5, PGSIZE); // fill with junk
  return (void*)r;
}
```

- vm.c中添加如下四个函数，详细说明已在注释中，这些函数中用到了`walk`，记得在***defs.h***中添加声明，最后也需要将这些函数的声明添加到***defs.h***，在cowalloc中，读取内存引用计数，如果为1，说明只有当前进程引用了该物理内存（其他进程此前已经被分配到了其他物理页面），就只需要改变PTE使能`PTE_W`；否则就分配物理页面，并将原来的内存引用计数减1。该函数需要返回物理地址，这将在`copyout`中使用到。

```cpp
int             
cowpage(uint64 va){
    pte_t *pte;
  struct proc *p = myproc();
  
  return ( va < p->sz )// 在进程内存范围内
    && ((pte = walk(p->pagetable, va, 0))!=0)
    && (*pte & (PTE_COW | PTE_V)); //页表项存在且对应的是一个lazy allocation页
}

/**
 * @brief cowalloc copy-on-write分配器
 * @param pagetable 指定页表
 * @param va 指定的虚拟地址,必须页面对齐
 * @return 分配后va对应的物理地址，如果返回0则分配失败
 */
void*           
cowalloc(uint64 va){
  pte_t* pte;
  struct proc *p = myproc();
  uint64 pa ;
  if(va % PGSIZE != 0)
    return 0;
    // panic("cowalloc:PGSIZE");
  /* 获取对应的物理地址 */
  if((pa = walkaddr(p->pagetable, va)) == 0)
    return 0;
    // panic("cowalloc:walkaddr");
  /* 获取对应的pte */
  pte = walk(p->pagetable, va, 0);

  if(krefcnt((char*)pa) == 1){
    /* 只剩下一个进程引用，直接更改权限 */
    *pte |= PTE_W;
    *pte &= ~PTE_COW;
    return (void*)pa;
  }else{
    /* 多个进程引用该物理地址 */
    char* mem;
    if( (mem = kalloc()) == 0)
      return 0;
      // panic("cowalloc: kalloc");
    // 复制旧页面内容到新页
    memmove(mem, (char*)pa, PGSIZE);
    // 清除PTE_V，否则在mappagges中会判定为remap
     *pte &= ~PTE_V;

    // 为新页面添加映射
    if(mappages(p->pagetable, va, PGSIZE, (uint64)mem, (PTE_FLAGS(*pte) | PTE_W) & ~PTE_COW) != 0) {
      kfree(mem);
      *pte |= PTE_V;
      // panic("cowalloc : mappages");
      return 0;
    }

    // 将原来的物理内存引用计数减1
    kfree((char*)PGROUNDDOWN(pa));
    return mem;
  }

}

/**
 * @brief krefcnt 获取内存的引用计数
 * @param pa 指定的内存地址
 * @return 引用计数
 */
int krefcnt(void* pa) {
  return ref.cnt[(uint64)pa / PGSIZE];
}

/**
 * @brief kaddrefcnt 增加内存的引用计数
 * @param pa 指定的内存地址
 * @return 0:成功 -1:失败
 */
int kaddrefcnt(void* pa) {
  if(((uint64)pa % PGSIZE) != 0 || (char*)pa < end || (uint64)pa >= PHYSTOP)
    return -1;
  acquire(&ref.lock);
  ++ref.cnt[(uint64)pa / PGSIZE];
  release(&ref.lock);
  return 0;
}
```

- 修改`freerange`

```cpp
void
freerange(void *pa_start, void *pa_end)
{
  char *p;
  p = (char*)PGROUNDUP((uint64)pa_start);
  for(; p + PGSIZE <= (char*)pa_end; p += PGSIZE) {
    // 在kfree中将会对cnt[]减1，这里要先设为1，否则就会减成负数
    ref.cnt[(uint64)p / PGSIZE] = 1;
    kfree(p);
  }
}
```

**(3).** 修改`uvmcopy`，不为子进程分配内存，而是使父子进程共享内存，但禁用`PTE_W`，同时标记`PTE_F`，记得调用`kaddrefcnt`增加引用计数

```cpp
// Given a parent process's page table, copy
// its memory into a child's page table.
// Copies both the page table and the
// physical memory.
// returns 0 on success, -1 on failure.
// frees any allocated pages on failure.
int
uvmcopy(pagetable_t old, pagetable_t new, uint64 sz)
{
  pte_t *pte;
  uint64 pa, i;
  uint flags;
  // char *mem;

  for(i = 0; i < sz; i += PGSIZE){
    if((pte = walk(old, i, 0)) == 0)
      panic("uvmcopy: pte should exist");
    if((*pte & PTE_V) == 0)
      panic("uvmcopy: page not present");
    pa = PTE2PA(*pte);
    /* 修改父进程、子进程叶子pte标志位 */
    *pte = (*pte & ~PTE_W) | PTE_COW;
    flags = PTE_FLAGS(*pte);
    /*不拷贝物理内存 */
    // if((mem = kalloc()) == 0)
      // goto err;
    // memmove(mem, (char*)pa, PGSIZE);
    if(mappages(new, i, PGSIZE, pa, flags) != 0){
      // kfree(pa);
      goto err;
    }
  /* 增加物理页引用次数 */
    kaddrefcnt((char*)pa);
  }

  return 0;

 err:
  uvmunmap(new, 0, i / PGSIZE, 1);
  return -1;
}
```

**(4).** 修改`usertrap`，处理页面错误

```cpp
uint64 cause = r_scause();
if(cause == 8) {
  ...
} else if((which_dev = devintr()) != 0){
  // ok
} else if(cause == 13 || cause == 15) {
  uint64 fault_va = r_stval();  // 获取出错的虚拟地址
  if(fault_va >= p->sz
    || cowpage(p->pagetable, fault_va) != 1
    || cowalloc(p->pagetable, PGROUNDDOWN(fault_va)) == 0)
    p->killed = 1;
} else {
  ...
}
```

**(5).** 在`copyout`中处理相同的情况，如果是COW页面，需要更换`pa0`指向的物理地址

```cpp
while(len > 0){
  va0 = PGROUNDDOWN(dstva);
  pa0 = walkaddr(pagetable, va0);

  // 处理COW页面的情况
  if(cowpage(pagetable, va0)) {
    // 更换目标物理地址
    pa0 = (uint64)cowalloc(pagetable, va0);
  }

  if(pa0 == 0)
    return -1;

  ...
}
```