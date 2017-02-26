#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // record the ans of (string begin in 'pos')
    int dp(int pos, string &s, vector<int> &rec) {
        if (rec[pos] != -1)
            return rec[pos];
        int ret = 0;
        // one number
        if (s[pos] > '0')
            ret += dp(pos + 1, s, rec);
        // two number
        if (pos + 1 < s.length() && s.substr(pos, 2) >= "10" && s.substr(pos, 2) <= "26")
            ret += dp(pos + 2, s, rec);
        return rec[pos] = ret;
    }

public:
    int numDecodings(string s) {
        if (s == "")
            return 0;
        vector<int> rec(s.length() + 1, -1);
        rec[s.length()] = 1;
        return dp(0, s, rec);
    }
};

int main() {
    string ss;
    Solution s;
    while (cin >> ss)
        cout << s.numDecodings(ss) << endl;
    return 0;
}

