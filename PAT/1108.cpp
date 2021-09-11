#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int num, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int flag = 0;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        // printf("a: %s\n",a);
        sprintf(b, "%.2f", temp);
        // printf("b: %s\n",b);
        for (int j = 0; j < strlen(a); j++)
            if (a[j] != b[j])
                flag = 1;
        // if (strcmp(a, b) != 0)
        //     flag = 1;
        if (flag || temp < -1000 || temp > 1000)
        {
            printf("ERROR: %s is not a legal number\n", a);
        }
        else
        {
            sum += temp;
            cnt++;
        }
    }

    if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}