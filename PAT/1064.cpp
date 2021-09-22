#include<iostream>
#include<algorithm>
using namespace std;

int in[1010], sequence[1010],num, weight=0;

void inorder(int root)
{
    if(root >= num) return ;
    inorder(2*root +1);
    sequence[root] = in[weight++];
    inorder(2*root +2);
}

int main()
{
    cin >> num;
    for(int i=0; i<num; i++)
        cin >> in[i];
    
    sort(in, in+num);

    inorder(0);

    cout<<sequence[0];

    for(int i=1; i<num; i++)
        cout << " " << sequence[i];
    return 0;
}