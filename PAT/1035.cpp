//看了题解，本身对vector的运用还不够自如

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> data;
    int times;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        int flag = 0;
        string str, name;
        cin >> name >> str;
        for (int j = 0; j < str.length(); j++)
        {
            switch (str[j])
            {
            case '1':
                str[j] = '@';
                flag = 1;
                break;
            case '0':
                str[j] = '%';
                flag = 1;
                break;
            case 'l':
                str[j] = 'L';
                flag = 1;
                break;
            case 'O':
                str[j] = 'o';
                flag = 1;
                break;
            default:
                break;
            }
        }
        if (flag)
        {
            string temp = name + " " + str;
            data.push_back(temp);
        }
    }

    int len = data.size();
    if (len)
    {
        cout << len << endl;
        for (int i = 0; i < len; i++)
        {
            cout << data[i] << endl;
        }
    }
    else if (times == 1)
    {
        cout << "There is 1 account and no account is modified" << endl;
    }
    else
    {
        cout << "There are " << times << " accounts and no account is modified" << endl;
    }
    return 0;
    
}