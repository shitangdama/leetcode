<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length())
            swap(word1, word2);

        vector<int> dp(word2.length() + 1);    // word2 will cost less space
        // init
        for (int i = 0; i < dp.size(); ++i)
            dp[i] = i;

        int upleft = 0;        // Record the dp[i-1][j-1]. It must be used.
        for (int i = 1; i <= word1.size(); ++i) {
            upleft = dp[0];
            dp[0] = i;

            for (int j = 1; j <= word2.size(); ++j) {
                int rec = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = upleft;
                else
                    dp[j] = min(upleft, min(dp[j], dp[j - 1])) + 1;
                upleft = rec;
            }
        }
        return dp[word2.length()];
    }
};
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        
        vector<vector<int> > f(row, vector<int>(col));

        for (int i = 0; i < row; i++)
            f[i][0] = i;

        for (int i = 0; i < col; i++)
            f[0][i] = i;

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
            }

        return f[row-1][col-1];
    }
};

int main() {
    string a, b;
    Solution s;
    cin >> a >> b;
    cout << s.minDistance(a, b) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length())
            swap(word1, word2);

        vector<int> dp(word2.length() + 1);    // word2 will cost less space
        // init
        for (int i = 0; i < dp.size(); ++i)
            dp[i] = i;

        int upleft = 0;        // Record the dp[i-1][j-1]. It must be used.
        for (int i = 1; i <= word1.size(); ++i) {
            upleft = dp[0];
            dp[0] = i;

            for (int j = 1; j <= word2.size(); ++j) {
                int rec = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = upleft;
                else
                    dp[j] = min(upleft, min(dp[j], dp[j - 1])) + 1;
                upleft = rec;
            }
        }
        return dp[word2.length()];
    }
};
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        
        vector<vector<int> > f(row, vector<int>(col));

        for (int i = 0; i < row; i++)
            f[i][0] = i;

        for (int i = 0; i < col; i++)
            f[0][i] = i;

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
            }

        return f[row-1][col-1];
    }
};

int main() {
    string a, b;
    Solution s;
    cin >> a >> b;
    cout << s.minDistance(a, b) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
