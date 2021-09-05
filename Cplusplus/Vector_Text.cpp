/*
 * @Author: your name
 * @Date: 2021-06-15 12:48:30
 * @LastEditTime: 2021-06-15 12:49:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \MyProject\Cplusplus\Vector_Text.cpp
 */

#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib> // qsort, bsearch, NULL
​using namespace std;

void test_array() {
    cout << "\ntest_array().......... \n";
​
array<long, ASIZE> c;
​
clock_t timeStart = clock();
    for (long i = 0; i < ASIZE; ++i) {
        c[i] = rand();
    }
    cout << "milli-seconds : " << (clock() - timeStart) << endl;    
    cout << "array.size()= " << c.size() << endl;
    cout << "array.front()= " << c.front() << endl;
    cout << "array.back()= " << c.back() << endl;
    cout << "array.data()= " << c.data() << endl;
​
long target = get_a_target_long();
​
    timeStart = clock();
    ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
long *pItem = (long *) ::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
    cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl;    //
    if (pItem != NULL)
        cout << "found, " << *pItem << endl;
    else
        cout << "not found! " << endl;
}