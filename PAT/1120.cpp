#include<iostream>
#include<set>


int getnum(int num)
{
    int sum =0;
    while(num!=0)
    {
        sum += num%10;
        num /= 10;
    }
    return sum;
}
using namespace std;
 int main()
 {
     int num;
    cin >> num;
    set<int> data;
    for(int i=0; i<num; i++)
    {
        int temp;
        cin >> temp;
        data.insert(getnum(temp));
    }

    cout << data.size() <<endl;
    
    for(auto lt = data.begin(); lt != data.end(); lt++)
    {
        if(lt!=data.begin()) cout<<" ";
        cout<<*lt;
    }

    return 0;
 }