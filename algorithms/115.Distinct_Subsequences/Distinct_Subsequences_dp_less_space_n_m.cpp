#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.length();
        int m = T.length();

        vector<int> dp(m + 1);

        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                if (S[i] == T[j])
                    dp[j + 1] += dp[j];
            }
        }

        return dp[m];
    }
};
int main() {
    string a, b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.numDistinct(a, b) << endl;
    }
    return 0;
}
