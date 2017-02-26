#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<int> dp(len + 1);
        dp[0] = 1;

        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i; ++j) {
                // check
                if (wordDict.find(s.substr(i-j, j)) != wordDict.end()) {
                    dp[i] = dp[i - j];
                }
                // if is matched
                if (dp[i])
                    break;
            }
        }

        return dp[len];
    }
};
// LeetCode, Word Break
// ���棬ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // ����Ϊn���ַ�����n+1������
        vector<bool> f(s.size() + 1, false);
        f[0] = true; // ���ַ���
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};

int main() {
    Solution s;
    string a, b;
    int n;
    unordered_set<string> wordDict;
    cin >> a;
    cin >> n;
    while (n--) {
        cin >> b;
        wordDict.insert(b);
    }

    cout << s.wordBreak(a, wordDict) << endl;
    return 0;
}

