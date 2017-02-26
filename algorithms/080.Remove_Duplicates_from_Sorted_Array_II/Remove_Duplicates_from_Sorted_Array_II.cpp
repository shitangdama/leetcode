#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int ret = 0;
        for (int i = 0; i < nums.size() - 2; i++)
            if (nums[i] != nums[i + 1] || nums[i] != nums[i + 2])
                nums[ret++] = nums[i];
        nums[ret++] = nums[nums.size() - 2];
        nums[ret++] = nums[nums.size() - 1];
        return ret;
    }
};
int main() {
    Solution s;
    int n, A[100];
    while (cin >>n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int res = s.removeDuplicates(A, n);
        for (int i = 0; i < res; i++)
            cout << A[i] << ' ';
        cout << endl;
    }
    return 0;
}

