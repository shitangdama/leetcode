<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1);

        // init
        for (int i = 0; i <= n; ++i)
            dp[i] = i - 1;

        // dp
        for (int i = 0; i < n; ++i) {
            // odd
            for (int j = 0; i - j >= 0 && i + j < n
                    && s[i - j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            // even
            for (int j = 1; i - j + 1 >= 0 && i + j < n
                    && s[i - j + 1] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j + 1] + 1);
        }

        return dp[n];
    }
};

int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1);

        // init
        for (int i = 0; i <= n; ++i)
            dp[i] = i - 1;

        // dp
        for (int i = 0; i < n; ++i) {
            // odd
            for (int j = 0; i - j >= 0 && i + j < n
                    && s[i - j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            // even
            for (int j = 1; i - j + 1 >= 0 && i + j < n
                    && s[i - j + 1] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j + 1] + 1);
        }

        return dp[n];
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
