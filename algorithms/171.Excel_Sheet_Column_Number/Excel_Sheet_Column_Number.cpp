#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        for (char i : s)
            col = col * 26 + (i - 'A' + 1);
        return col;
    }
};
class Solution {
 public:
  int titleToNumber(string s) {
    int result = 0;
    int d = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
      result += (s[i] - ('A' - 1)) * d;
      d *= 26;
    }
    return result;
  }
};

int main() {
    string str;
    Solution s;
    while (cin >> str)
        cout << s.titleToNumber(str) << endl;
    return 0;
}

