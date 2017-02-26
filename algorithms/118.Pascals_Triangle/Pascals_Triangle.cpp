<<<<<<< HEAD
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
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;

        result.push_back(vector<int>(1,1)); //first row

        for(int i = 2; i <= numRows; ++i) {
            vector<int> current(i,1);  // ����
            const vector<int> &prev = result[i-2];  // ��һ��

            for(int j = 1; j < i - 1; ++j) {
                current[j] = prev[j-1] + prev[j]; // ���ϽǺ����Ͻ�֮��
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

=======
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
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;

        result.push_back(vector<int>(1,1)); //first row

        for(int i = 2; i <= numRows; ++i) {
            vector<int> current(i,1);  // ����
            const vector<int> &prev = result[i-2];  // ��һ��

            for(int j = 1; j < i - 1; ++j) {
                current[j] = prev[j-1] + prev[j]; // ���ϽǺ����Ͻ�֮��
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

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
