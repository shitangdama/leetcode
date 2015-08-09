#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int sz = nums.size();
    vector<bool> rec(sz + 2);
    for (int i = 0; i < sz; i++) {
            if (nums[i] < sz + 2 && nums[i] > 0)
                rec[nums[i]] = true;
        }
        for (int i = 1; i < sz + 2; i++)
            if (!rec[i])
                return i;
    }
};

int main() {
    int n, A[100];
    Solution s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.firstMissingPositive(A, n) << endl;
    return 0;
}

