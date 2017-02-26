class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                if (nums[i] + nums[j] + nums[k] >= target) {
                    k--;
                } else {
                    ans += (k - j);
                    j++;
                }
            }
        }
        return ans;
    }
};
// 3Sum Smaller
class Solution {
public:
  int threeSumSmaller(vector<int>& a, int target) {
    int n = a.size(), r = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      int j = i+1, k = n-1;
      for (; j < n; j++) {
        for (; j < k && a[i]+a[j]+a[k] >= target; k--);
        if (j < k)
          r += k-j;
      }
    }
    return r;
  }
};