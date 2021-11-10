#include<iostream>
using namespace std;
int main()
{
    cout<< ((uint32_t*)(0xb00))<<endl;
    cout<<0xb00<<endl;
    cout<<(uint32_t)(0xb00)<<endl;
    return 0;
}