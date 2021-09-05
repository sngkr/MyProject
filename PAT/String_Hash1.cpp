#include <iostream>
#include <string.h>
using namespace std;

typedef unsigned long long ULL;
const int maxn = 1e5 + 5;
const int base = 13331;
ULL hash_[maxn], xp[maxn];
char str[100];


void init(int len)
{
    xp[0] = 1;
    for (int i = 1; i < len; i++)
    {
        xp[i] = xp[i - 1] * base;
        hash_[i] = hash_[i - 1] * base + str[i] - 'A' + 1;
    }
    return;
}
ULL get_hash(int L, int R)
{
    return hash_[R] - hash_[L - 1] * xp[R - L + 1];
}

int main()
{
    scanf("%s", str+1);
    int len = strlen(str+1);
    init(len);
    int times=0;
    scanf("%d",&times);
    while(times--)
    {
        int L1, R1, L2, R2;
        scanf("%d %d %d %d", &L1, &R1, &L2, &R2 );  
        if(get_hash(L1, R1) == get_hash(L2, R2))
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}