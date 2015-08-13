#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > ans(2);

        ans[0&1].push_back(1);
        if (rowIndex == 0)
            return ans[0&1];

        for (int i = 1; i <= rowIndex; i++) {
            ans[i&1].clear();
            ans[i&1].push_back(1);
            for (int j = 1; j < i; j++)
                ans[i&1].push_back(ans[!(i&1)][j - 1] + ans[!(i&1)][j]);
            ans[i&1].push_back(1);
        }
        return ans[rowIndex&1];
    }
};

// LeetCode, Pascal's Triangle II
// 滚动数组，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> array;
		for (int i = 0; i <= rowIndex; i++) {
			for (int j = i - 1; j > 0; j--){
				array[j] = array[j - 1] + array[j];
			}
			array.push_back(1);
		}
		return array;
	}
};
int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<int> v;
        v = s.getRow(n);
        for (int i : v)
            printf("%d ", i);
        puts("");
    }
    return 0;
}

