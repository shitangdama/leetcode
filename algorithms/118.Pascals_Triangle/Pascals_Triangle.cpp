#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows);
        if (numRows == 0)
            return ans;
        for (int i = 0; i < numRows; i++) {
            ans[i].push_back(1);
            for (int j = 1; j < i; j++)
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            if (i)
                ans[i].push_back(1);
        }
        return ans;
    }
};
// LeetCode, Pascal's Triangle
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;

        result.push_back(vector<int>(1,1)); //first row

        for(int i = 2; i <= numRows; ++i) {
            vector<int> current(i,1);  // 本行
            const vector<int> &prev = result[i-2];  // 上一行

            for(int j = 1; j < i - 1; ++j) {
                current[j] = prev[j-1] + prev[j]; // 左上角和右上角之和
            }
            result.push_back(current);
        }
        return result;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<vector<int> > ans = s.generate(n);
        for (vector<int> i : ans) {
            for (int j : i)
                printf("%d ", j);
            puts("");
        }
    }
    return 0;
}

