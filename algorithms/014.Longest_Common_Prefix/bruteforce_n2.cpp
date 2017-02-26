#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); ++j)
                if (i >= strs[j].length() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        }
        return strs[0];
    }
};

int main() {
    Solution s;
    int n;
    string t;
    while (cin >> n) {
        vector<string> strs;;
        while (n--) {
            cin >> t;
            strs.push_back(t);
        }
        cout << s.longestCommonPrefix(strs) << endl;
    }
    return 0;
}

