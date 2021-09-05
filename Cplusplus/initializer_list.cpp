/*
 * @Author: your name
 * @Date: 2021-06-13 08:12:01
 * @LastEditTime: 2021-06-13 19:57:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \MyProject\Cplusplus\initializer_list.cpp
 */
#include<iostream>
using namespace std;

class P 
{
    public :
        P(int a , int b)
        {
            cout<<"P(int a, int b) , a="<<a << ", b="<<b<<endl;
        }

        P(initializer_list<int> initlist)
        {
            cout<<"P(initializer_list<int> initlist) =";
            for(auto i : initlist)
            {
                cout<< i << ' ';
            }
            cout << endl;
        }
};

`
int main()
{
    P p(22,1);
    P q({1,2,3,4});
    P r{22,1};
    return 0;
}