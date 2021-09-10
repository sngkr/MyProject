#include <stdio.h>
#define maxn 500
void ALG1(const int data[], int len)
{
    for(int i=0; i<len; i++)
    {
        int temp = data[i];
        for(int j=i+1; j<len; j++)
        {
            if(temp == data[j])
            {
                printf("YES\n");
                return ;
            }
        }
    }
    printf("NO\n");
    return ;
}
int main()
{
    int data[maxn];
    int num = 0;
    scanf("%d", &num);
    for (int i = 0, temp = 0; i < num; i++)
    {
        scanf("%d", &temp);
        for (int j = 0; j < temp; j++)
        {
            scanf("%d", &data[j]);
        }
        ALG1(data, temp);
    }
    return 0;
}