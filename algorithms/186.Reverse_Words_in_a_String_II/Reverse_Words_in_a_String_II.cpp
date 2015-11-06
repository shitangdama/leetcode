#include <bits/stdc++.h>

using namespace std;


class Solution {
 public:
  void reverseWords(string &s) {
    int i = 0, j = s.size() - 1;
    while(i < j) { swap(s[i], s[j]); i ++; j --; }
    i = 0;
    while(i < s.size()) {
      int j = i + 1;
      while(j < s.size() && s[j] != ' ') j ++;
      j -= 1;
      int tmp = j + 2;
      while(i < j) { swap(s[i], s[j]); i ++; j --; }
      i = tmp;
    }
  }
};

int main() {
        return 0;
}


