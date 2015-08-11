#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // vector<int> f(nums.size(), 0);
        int f[2];        // compress to O(1)
        f[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            f[i&1] = max(f[(i-1)&1], nums[i - 1]) - 1;
            if (f[i&1] < 0)
                return false;
        }
        return f[(nums.size()-1)&1] >= 0;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.canJump(A, n) << endl;
    }
    return 0;
}

