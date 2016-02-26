class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 2) return;
        for(int i = 1; i < n; i++) {
            if(i % 2 == 1) {
                if(nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            } else {
                if(nums[i] > nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
};
// Wiggle Sort
class Solution {
public:
  void wiggleSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++)
      if (i%2 ^ a[i-1] < a[i])
        swap(a[i-1], a[i]);
  }
};