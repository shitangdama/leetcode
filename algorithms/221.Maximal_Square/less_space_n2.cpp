<<<<<<< HEAD

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        // roll array
        vector<int> up(m);
        vector<int> left(n);
        vector<vector<int> > dp(2, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) {
                    up[j] = matrix[i][j] - '0';
                } else {
                    up[j] = matrix[i][j] == '1' ? up[j] + 1 : 0;
                }
                if (j == 0) {
                    left[i] = matrix[i][j] - '0';
                } else {
                    left[i] = matrix[i][j] == '1' ? left[i] + 1 : 0;
                }
                if (i == 0 || j == 0) {
                    dp[i&1][j] = matrix[i][j] - '0';
                } else {
                    dp[i&1][j] = min(dp[(i - 1)&1][j - 1] + 1, min(up[j], left[i]));
                }
                ans = max(ans, dp[i&1][j]);
            }
        }
        return ans * ans;
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
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        // roll array
        vector<int> up(m);
        vector<int> left(n);
        vector<vector<int> > dp(2, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) {
                    up[j] = matrix[i][j] - '0';
                } else {
                    up[j] = matrix[i][j] == '1' ? up[j] + 1 : 0;
                }
                if (j == 0) {
                    left[i] = matrix[i][j] - '0';
                } else {
                    left[i] = matrix[i][j] == '1' ? left[i] + 1 : 0;
                }
                if (i == 0 || j == 0) {
                    dp[i&1][j] = matrix[i][j] - '0';
                } else {
                    dp[i&1][j] = min(dp[(i - 1)&1][j - 1] + 1, min(up[j], left[i]));
                }
                ans = max(ans, dp[i&1][j]);
            }
        }
        return ans * ans;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
