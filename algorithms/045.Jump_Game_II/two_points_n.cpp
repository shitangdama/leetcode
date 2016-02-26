#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int start = 0, end = 1;
        int step = 0;
        while (end <= nums.size()) {
            int new_end = end;

            // update new [start, end] base on old [start, end]
            step++;
            for (int i = start; i < end; ++i) {
                if (nums[i] + i + 1 >= nums.size())
                    return step;
                new_end = max(new_end, nums[i] + i + 1);
            }

            start = end;
            end = new_end;

            if (start == end)    // cannot reach
                return 0;
        }

        // this won't go
        return step;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.jump(A, n) << endl;
    }
    return 0;
}
