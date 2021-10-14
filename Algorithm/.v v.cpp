#include<iostream>

using namespace std;

int pow(int n, int m){
    int sum = 1;
    int tmp = m;
    while(n != 0){
        if(n & 1 == 1){
            sum *= tmp;
        }
        tmp *= tmp;
        n = n >> 1;
    }
    
    return sum;
}
