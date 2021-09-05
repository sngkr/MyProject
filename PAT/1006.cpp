// #include <iostream>
// using namespace std;

// int main()
// {
//     string ID_number, ID_Lock, ID_Unlock;
//     int in_h, in_m, in_s;
//     int out_h, out_m, out_s;
//     int min = 0, max = 90000;
//     int time;
//     cin >> time;
//     while (time--)
//     {
//         cin >> ID_number;
//         // cin >> in_h >> temp >> in_m >> temp >> in_s >> temp >> out_h >> temp >> out_m >> temp >> out_s;
//         scanf("%d:%d:%d %d:%d:%d", &in_h, &in_m, &in_s, &out_h, &out_m, &out_s);
//         int unlock = in_h * 3600 + in_m * 60 + in_s;
//         int lock = out_h * 3600 + out_m * 60 + out_s;

//         if (unlock < max)
//         {
//             max = unlock;
//             ID_Unlock = ID_number;
//         }
//         if (lock > min)
//         {
//             min = lock;
//             ID_Lock = ID_number;
//         }
//     }
//     cout << ID_Unlock << " " << ID_Lock;
//     return 0;
// }

//看到别人用strcmp后想到利用string直接判断
#include <iostream>

using namespace std;

int main()
{
    string ID_number, ID_Lock, ID_Unlock;
    string in_time, out_time;
    string min = "00:00:00", max = "23:59:59";
    int time;
    cin >> time;
    while (time--)
    {
        cin >> ID_number >> in_time >> out_time;
        if (max > in_time)
        {
            max = in_time;
            ID_Unlock = ID_number;
        }
        if (out_time > min)
        {
            min = out_time;
            ID_Lock = ID_number;
        }
    }
    cout << ID_Unlock << " " << ID_Lock;
    return 0;
}