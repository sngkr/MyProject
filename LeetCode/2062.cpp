#include <iostream>

using namespace std;
int countVowelSubstrings(string word) {
  int num, total = 0;
  int T = 1 << 'a' - 'a' | 1 << 'e' - 'a' | 1 << 'i' - 'a' | 1 << 'o' - 'a' |
          1 << 'u' - 'a';
  for (int i = 0; i < word.length() - 4; i++) {
    num = 0;
    for (int j = i; j < word.length(); j++) {
      int temp = 1 << word[j] - 'a';
      cout << temp << endl;
      if (temp & T == 0) break;
      num |= temp;
      if (num == T) total++;
    }
  }
  return total;
}
int main() {
  string word;
  cin >> word;
  cout << countVowelSubstrings(word);
  return 0;
}