#include <bits/stdc++.h>

class Solution {
public:
    void reverseWords(string &s) {
        stringstream is(s);
        is >> s;
        string tmp;
        while (is >> tmp)
            s = tmp + ' ' + s;
        if (s[0] == ' ')    // if input is all space then s will be the same
            s = "";
    }
};
class Solution {
public:
void reverseWords(string &s)
  {
    string rs;
    for (int i = s.length()-1; i >= 0; )
    {
      while (i >= 0 && s[i] == ' ') i--;
      if (i < 0) break;
      if (!rs.empty()) rs.push_back(' ');
      string t;
      while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
      reverse(t.begin(), t.end());
      rs.append(t);
    }
    s = rs;
  }
};

int main() {
    Solution s;
    string str = "    ";
    s.reverseWords(str);
    cout << str << endl;
    return 0;
}

