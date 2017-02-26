#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 1;
        for (int i = 0; i < reach && reach < nums.size(); ++i)
            reach = max(reach, i + 1 + nums[i]);
        return reach >= nums.size();
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

