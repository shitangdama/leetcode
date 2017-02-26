<<<<<<< HEAD
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (nums[len] != nums[i]) {
                    swap(nums[len], nums[i]);
                }
                ++len;
            }
        }
    }
=======
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (nums[len] != nums[i]) {
                    swap(nums[len], nums[i]);
                }
                ++len;
            }
        }
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};