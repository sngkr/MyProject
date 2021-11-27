#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
  int letter[26] = {0}, flag[26] = {0};
  for (char ch : s) {
    letter[int(ch - 'a')]++;
  }

  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] > s[i + 1] and letter[int(s[i] - 'a')] > 1) {
      flag[i] = 1;
      letter[int(s[i] - 'a')]--;
    }
  }
  for (int i = s.length() - 1; i > 0; i--) {
    if (s[i] > s[i - 1] and letter[int(s[i] - 'a')]) {
      flag[i] = 1;
    }
  }
  string temp;
  for (int i = 0; i < s.length(); i--) {
      if(flag[i] != 1)
        temp.push_back(s[i]);
  }
  return temp;
}
int main() {
  string s;
  cin >> s;
  cout << removeDuplicateLetters(s);
}