#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> lefts;
        int max_len = 0, match_pos = -1;    // position of first
                                            // matching '(' - 1

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                lefts.push(i);
            else {
                if (lefts.empty())  // no matching left
                    match_pos = i;
                else {              // match a left
                    lefts.pop();
                    if (lefts.empty())
                        max_len = max(max_len, i - match_pos);
                    else
                        max_len = max(max_len, i - lefts.top());
                }
            }
        }

        return max_len;
    }
};

int main() {
    string test;
    Solution s;
    while (cin >> test)
        cout << s.longestValidParentheses(test) << endl;
    return 0;
}

