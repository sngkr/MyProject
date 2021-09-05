/*
 * @Author: your name
 * @Date: 2021-06-12 21:49:33
 * @LastEditTime: 2021-06-12 22:26:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \MyProject\Cplusplus\Variadic Templates.cpp
 */
#include<iostream>
#include<bitset>
#include<functional>
using namespace std;

// template<typename... Types>
// void print(const Types&... Args)
// {
//     cout<<Args<<endl;
// }

/* 
...就是所谓的pack
1、template parameters pack  模板参数包
2、function parameters types pack  函数参数类型包
3、function parameters pack 函数参数包

有种新的用法sizeof...(Args)判断参数的个数
 */
template<typename T, typename... Types>
void print(const T& FirstArgs, const Types&... Args)
{
    cout<<FirstArgs<<endl;
    print(Args...);
}




int main()
{
    print(7.8, "hello world! ", bitset<16>(377),42);
}