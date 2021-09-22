#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string female, male;

    int femalescore = -1, malescore = 101;

    for (int i = 0; i < n; i++)
    {
        string name, sex, num;
        int score;

        cin >> name >> sex >> num >> score;

        if (sex == "F")
        {
            if (femalescore < score)
            {
                femalescore = score;
                female = name + " " + num;
            }
        }
        else if (malescore > score)
        {
            malescore = score;
            male = name + " " + num;
        }
    }
    if (femalescore != -1)
        cout << female << endl;
    else
        cout << "Absent\n";

    if (malescore != 101)
        cout << male << endl;
    else
        cout << "Absent\n";

    if (femalescore != -1 && malescore != 101)
    {
        cout << femalescore - malescore;
    }
    else
        cout << "NA";

    return 0;
}