#include <cstdio>
#include <climits>
int result[INT_MAX / 10];

int main()
{
    int times;
    scanf("%d", &times);

    for (int i = 0, num1, num2; i < times; i++)
    {
        int cnt = 0;
        scanf("%d", &num1);
        for (int j = 0, temp; j < num1; j++)
        {
            scanf("%d", &temp);
            result[temp] = 1;
        }
        scanf("%d", &num2);
        for (int j = 0; cnt < num2 && j < INT_MAX / 10; j++)
        {
            if (result[j] == 1)
            {
                /* 重置该数组元素，不再重复定义数组了 */
                result[j] =0;
                cnt++;
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}