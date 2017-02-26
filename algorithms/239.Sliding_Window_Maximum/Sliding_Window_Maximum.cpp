#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowMax;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();  
            dq.push_back(i);
            if (i >= k - 1) windowMax.push_back(nums[dq.front()]);
        }
        return windowMax;
    }
};
int main() {

    return 0;
}

