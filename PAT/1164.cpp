#include <iostream>
#include <cctype>
using namespace std;
string sentence;
char sou[26][7][6];
int main()
{
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++)
            scanf("%s\n", &sou[i][j]);

    char temp;
    cin >> sentence;

    for (int i, word, begin = 0; i < sentence.size(); i = begin)
    {
        if (isupper(sentence[i]))
        {
            for (int j = 0; j < 7; j++)
            {
                i = begin;
                while (isupper(sentence[i]))
                {
                    word = int(sentence[i]) - 65;
                    cout << sou[word][j] << " ";
                    i++;
                }
                cout << endl;
            }

            if (i + 1 < sentence.size())
                cout << "\n";
        }
        begin = i + 1;
    }
    return 0;
}

// for (int i = sentence.size() - 1; i > 0; i--)
// {
//     if (!isupper(sentence[i]))
//         sentence.pop_back();
//     else
//         break;
// }