#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 50
int board[BOARD_SIZE][BOARD_SIZE];
int dir[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
int fill_num = 1;
/* left：填充部位顶左 top: 填充部位顶上  */
void fill(int x, int y, int type)
{
    for (int i = 0; i < 4; i++)
        if (i != type)
            board[x + dir[i][0]][y + dir[i][1]] = fill_num;
    fill_num++;
}
/* 选每个棋盘的左上（x,y）坐标作为标识 */
void divide(int size, int x, int y, int bx, int by)
{
    /* 递归出口 */
    if (size < 2)
        return;

    int temp_size = (size >> 1); //即将划分的子棋盘大小
    /* 奇异点相对于棋盘中心的位置 */
    int is_left = (x >= (bx + temp_size)); //is_left==0 ? (左) : (右)
    int is_top = (y >= (by + temp_size));
    /* 遍历划分后的子棋盘 */
    for (int i = 0; i < 4; i++)
    {
        if (dir[i][0] == is_left && dir[i][1] == is_top)
        {
            /* 填充 */
            fill(bx + temp_size - 1, by + temp_size - 1, i);

            for (int j = 0; j < 4; j++)
            {
                if (j == i)
                    divide(temp_size, x, y, bx + temp_size * dir[j][0], by + temp_size * dir[j][1]);
                else
                    divide(temp_size, bx + temp_size - 1 + dir[j][0], by + temp_size - 1 + dir[j][1], bx + temp_size * dir[j][0], by + temp_size * dir[j][1]);
            }
        }
    }
}
int main()
{
    int num = 1;
    int size = 0;
    while (size <= 8)
    {
        fill_num = 1;
        size = 2 << num++;
        divide(size, rand() % size, rand() % size, 0, 0);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                printf("%02d  ", board[i][j]);
            printf("\n\n");
        }
    }
    return 0;
}