#include<iostream>

using namespace std;

int main()
{
    int a=0;
    const int * p = &a;
    const int *y = p;
    cout<<*y<<endl;
    return 0 ;
}