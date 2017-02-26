#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty())
            return 0;

        int ppre = 0, pre = 0, cur = 0;
        for (auto n : num) {
            cur = max(pre, ppre + n);
            ppre = pre;
            pre = cur;
        }

        return max(pre, ppre);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
            f[i] = max(f[i-2] + nums[i], f[i-1]);
        return f[n-1];
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
           int pre = 0 , pre_2 = 0;
    for(int i=0;i<nums.size();i++)
       swap(pre,pre_2=max(pre_2+nums[i],pre));
    return pre; 
    }
};
int main() {
    int n;
    Solution s;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
        cin >> i;
    cout << s.rob(num) << endl;
    return 0;
}

