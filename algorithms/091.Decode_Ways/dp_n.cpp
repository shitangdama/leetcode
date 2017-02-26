<<<<<<< HEAD
/*Descripton:  dp[i] = dp[i - 1](if s[i] is valid) + dp[i - 2](if s[i,i+1] is valid)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return s[0] != '0';

        int dp[2], rec;
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for (int i = 2; i <= s.length(); ++i) {
            rec = 0;
            if (s[i - 1] != '0')
                rec += dp[(i - 1)&1];
            if (s.substr(i - 2, 2) <= "26" && s[i - 2] != '0')
                rec += dp[i&1];
            dp[i&1] = rec;
        }
        return dp[s.length()&1];
    }
};

int main() {
    string ss;
    Solution s;
    while (cin >> ss)
        cout << s.numDecodings(ss) << endl;
    return 0;
}


=======
/*Descripton:  dp[i] = dp[i - 1](if s[i] is valid) + dp[i - 2](if s[i,i+1] is valid)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return s[0] != '0';

        int dp[2], rec;
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for (int i = 2; i <= s.length(); ++i) {
            rec = 0;
            if (s[i - 1] != '0')
                rec += dp[(i - 1)&1];
            if (s.substr(i - 2, 2) <= "26" && s[i - 2] != '0')
                rec += dp[i&1];
            dp[i&1] = rec;
        }
        return dp[s.length()&1];
    }
};

int main() {
    string ss;
    Solution s;
    while (cin >> ss)
        cout << s.numDecodings(ss) << endl;
    return 0;
}


>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
