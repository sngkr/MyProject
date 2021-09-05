#include<iostream>
#include<map>
#include<cctype>

using namespace  std;

int main()
{
    map<string , int > data;
    string str, word;
    getline(cin,str);

    for(int i=0; i<str.length(); i++)
    {
        word.clear();
        while(i< str.length() && isalnum(str[i]))
        {
            word += tolower(str[i]);
            i++;
        }

        if(!word.length())
        continue;

        data[word]++;
    }

    string result ;
    int max=-1;
    for(auto iter = data.cbegin(); iter!= data.cend(); iter++)
    {
        if(iter->second > max)
        {
            max = iter->second;
            result = iter->first;
        }
    }
    cout<<result <<" " << max;
    return 0;
}