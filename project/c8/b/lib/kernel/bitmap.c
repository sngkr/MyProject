#include"bitmap.h"
#include"stdint.h"
#include"string.h"
#include"print.h"
#include"interrupt.h"
#include"debug.h"

//将位图初始化
void bitmap_init(struct bitmap* btmp)
{
    // 将btmp->bits 强制类型转换为uint8_t*  
    // 将位图每一位
    memset(btmp->bits, 0, btmp->btmp_bytes_len);
}

// 判断第 bit_idx 位是否为1，if 1 return TRUE ,else return FALSE
bool bitmap_scan_test(struct bitmap* btmp, uint32_t bit_idx)
{
    //向下取整，用于索引数组下标
    uint32_t byte_idx = bit_idx / 8;
    // 取余用于索引数组内的位---- odd 有剩余的意思
    uint32_t bit_odd = bit_idx % 8;
    // &是二元运算符，它以特定的方式的方式组合操作数中对应的位 如果对应的位都为1，那么结果就是1， 如果任意一个位是0 则结果就是0
    return (btmp->bits[byte_idx] & (BITMAP_MASK << bit_odd));
}

//在位图中申请连续cnt个位，成功，则返回其起始下标，失败返回-1

int bitmap_scan(struct bitmap* btmp, uint32_t cnt)
{
    uint32_t idx_byte = 0;
    // 逐字节比较
    while((0xff == btmp->bits[idx_byte]) && (idx_byte < btmp-> btmp_bytes_len))
    {
        // 如果0xff == btmp..... 这个表达式成立表明该字节内已经没有空闲位，向下一个字节继续找
        idx_byte++;
    }
    ASSERT(idx_byte < btmp->btmp_bytes_len);
    // 若该内存池找不到可用空间
    if(idx_byte == btmp->btmp_bytes_len)
    {
        return -1;
    }

    // 若在位图数组范围内的某字节内找到了空闲位，在该字节内逐位比对，返回空闲位的索引

    int idx_bit = 0;
    //btmp->bits[idx_byte]这个字节逐位对比
    while((uint8_t)(BITMAP_MASK << idx_bit) & btmp->bits[idx_byte])
    {
        idx_bit++;
    }
    //空闲位在bitmap中的下标
    int bit_idx_start = idx_byte * 8 + idx_bit;
    if(cnt == 1)
    {
        return bit_idx_start;
    }

    uint32_t bit_left = (btmp->btmp_bytes_len * 8 - bit_idx_start);
    //记录还有多少位可以判断
    uint32_t next_bit = bit_idx_start + 1;
    //记录找到的空闲位的个数
    uint32_t count = 1;

    //先置为 -1 若找不到直接返回就可以
    bit_idx_start = -1;
    
    while(bit_left-- > 0)
    {
        if(!(bitmap_scan_test(btmp, next_bit)))
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if(count == cnt)
        {
            bit_idx_start = next_bit - cnt + 1;
            break;
        }
        next_bit++;
    }
    
    return bit_idx_start;
}

//将位图btmp的bit_idx位设置为value
void bitmap_set(struct bitmap* btmp, uint32_t bit_idx, int8_t value)
{
    ASSERT((value == 0) || (value == 1));
    uint32_t byte_idx = bit_idx / 8;//向下取整用于索引数组的下标
    uint32_t bit_odd = bit_idx % 8;//取余用于索引数组内的位
    if(value)
    {
        btmp->bits[byte_idx] |= (BITMAP_MASK << bit_odd);
    }
    else
    {
        btmp->bits[byte_idx] &= ~(BITMAP_MASK << bit_odd);
    }
}