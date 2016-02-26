#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> wnd;
        for (int i = 0; i < nums.size(); ++i) {
            // keep size
            if (i > k)
                wnd.erase(nums[i - k - 1]);
            auto pos = wnd.lower_bound((long long)nums[i] - t);
            if (pos != wnd.end() && *pos <= (long long)nums[i] + t)
                return true;
            wnd.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution s;
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << s.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    return 0;
}

