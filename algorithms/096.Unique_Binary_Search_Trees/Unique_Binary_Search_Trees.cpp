/*  Descripton:  Interval dp
               dp[i] = dp[k] * dp[i-k-1] { 0<=k<=i-1 }
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 0; k < i; k++)
                dp[i] += dp[k] * dp[i - k - 1];
        }
        
        return dp[n];
    }
};

int main() {

    return 0;
}

