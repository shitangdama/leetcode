<<<<<<< HEAD
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
=======
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
