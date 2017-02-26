<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int sum = nums[0], mmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            mmax = max(mmax, sum);
        }
        return mmax;
    }
};

int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int sum = nums[0], mmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            mmax = max(mmax, sum);
        }
        return mmax;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
