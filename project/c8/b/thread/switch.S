[bits 32]
section .text
global switch_to
switch_to:
 ;--------备份线程当前环境---------
    push esi
    push edi
    push ebx
    push ebp
    ;---------上面一系列操作是遵顼ABI原则
    mov eax, [esp + 20]; 获取当前线程的PCB地址，这个值也可以看作self_kstack的地址，因为self_kstack在pcb的偏移为0
    mov [eax], esp;esp中保存的是栈顶指针

    mov eax, [esp+ 24];获取next
    mov esp, [eax]

    pop ebp
    pop ebx
    pop edi
    pop esi
    ret



