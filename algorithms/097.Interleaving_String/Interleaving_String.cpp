/*
*  Descripton:  dp[i][j] =
*               (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
*               ||
*               (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;

        int len1 = s1.length(), len2 = s2.length();
        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, true));
        
        // init
        for (int i = 1; i <= len1; ++i)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= len2; ++j)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);

        // dp
        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j)
                dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) ||
                    (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);

        return dp[len1][len2];
    }
};
class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {

int l1 = s1.length();
int l2 = s2.length();
int l3 = s3.length();

if (l1 + l2 != l3)
    return false;
bool **dp = new bool*[l1 + 1];
for (int i = 0; i <= l1; i++)
    dp[i] = new bool[l2+1];
dp[0][0] = true;
for (int i = 1; i <= l2; i++)
    dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
for (int i = 1; i <= l1; i++)
{
    dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    for (int j = 1; j <= l2; j++)
    {
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j-1] && s2[j - 1] == s3[i + j - 1]);
    }
}

    int res = dp[l1][l2];
    for (int i = 0; i <= l1; i++)
    delete []dp[i]; 
delete[] dp;
return res;
}

};
int main() {

    return 0;
}

