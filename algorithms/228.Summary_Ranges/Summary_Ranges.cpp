#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;

        // append a element
        int sz = nums.size();
        nums.push_back(nums[sz - 1]);
        ++sz;

        int start = 0;
        for (int i = 0; i < sz - 1; ++i) {
            if (nums[i + 1] - nums[i] != 1) {
                if (start == i) {
                    res.push_back(to_string(nums[i]));
                } else {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                }
                start = i + 1;
            }
        }

        // pop the element
        nums.pop_back();

        return res;
    }
};
class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;
    for (int i = 0; i < size_n;) {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else res.push_back(to_string(nums[start]));
        i = end+1;
    }
    return res;
}
};

int main() {

    return 0;
}

