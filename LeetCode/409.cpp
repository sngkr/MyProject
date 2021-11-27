#include <cstring>
#include <iostream>
using namespace std;
int longestPalindrome(string s) {
  // int temp[128]={0}, num=0;
  // for(int i=0; i<s.length(); i++){
  //     temp[s[i]]++;
  // }
  // for(int i : temp){
  //         num += i%2;
  // }
  // return num==0 ? s.length() : s.length() - num + 1;
  int hashmap[52], num = 0;
  memset(hashmap, 0, sizeof(hashmap));
  for (int i = 0; i < s.length(); i++) {
    if (s[i] <= 'z' or s[i] >= 'a')
      hashmap[int(s[i] - 'a')]++;
    else
      hashmap[int(s[i] - 'A' + 26)]++;
  }
  for (int i : hashmap) {
    num += i % 2;
  }
  return num == 0 ? s.length() : s.length() - num + 1;
}
int main() {
  string s;
  cin >> s;
  cout << longestPalindrome(s);
  return 0;
}