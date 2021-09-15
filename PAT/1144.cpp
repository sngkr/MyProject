#include<cstdio>
using namespace std;
bool data[4147483999] = {false} ;
// int str[10000001] = {0};
int main()
{
    int num; 
    scanf("%d", &num);

    // int min = 9999999;
    for(int i=0, temp=0; i<num; i++)
    {
        scanf("%d", &temp);
        if(temp > 0)
        {
            data[temp] = true;
            // str[i] = temp; 
        }
    }

    // int cnt =0;
    for(int i=1; i<4147483999; i++)
    {
        if(data[i] == false)
        {
            printf("%d", i);
            return 0;
        }
    }
}   

// #include<iostream>
// #include<map>
// using namespace std;

// int main()
// {
//     int num;
//     cin >> num;
//     map<int ,int > m;
//     for(int i=0, a; i<num; i++)
//     {
//         cin >>a;
//         m[a] ++;
//     }   

//     int n=0;
//     while(++n)
//         if(m[n] == 0) break;

//     cout<<n;
//     return 0;
// }