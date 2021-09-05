#include <cstdio>

int main()
{
    char str[] = {"WTL"};
    double rel = 1;
    for (int i = 0; i < 3; i++)
    {
        double temp, max = 0;
        int flag = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &temp);
            if (temp > max)
            {
                max = temp;
                flag = j;
            }
        }
        rel *= max;
        printf("%c ", str[flag]);
    }
    printf("%.2f",(rel*0.65-1)*2);
    return 0;
}

