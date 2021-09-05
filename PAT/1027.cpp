#include<iostream>
using namespace std;
int main()
{
    char data[] = {"0123456789ABC"};
    printf("#");
    for(int i=0, num; i<3; i++)
    {
        scanf("%d", &num);
        printf("%c%c",data[num/13],data[num%13]);
    }
    return 0;
}