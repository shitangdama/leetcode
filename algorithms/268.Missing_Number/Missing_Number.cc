class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = (nums.size() + 1) * nums.size() /2;
        for(auto i: nums)
            ret -= i;
        return ret;
    }
};
