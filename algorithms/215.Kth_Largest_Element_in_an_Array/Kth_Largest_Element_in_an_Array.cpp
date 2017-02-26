<<<<<<< HEAD
class Solution {

 public:
  int partition(vector<int> & nums, int lo, int hi) {
    int i = lo, j = hi + 1;
    while(1) {
      while(nums[++i] < nums[lo]) {
        if(i == hi) break;
      }
      while(nums[--j] > nums[lo]) {
        if(j == lo) break;
      }
      if(i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[lo], nums[j]);
    return j;
  }

  // O(N) with worst cast O(N*N)
  int findKthLargest(vector<int>& nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int lo = 0, hi = nums.size() - 1;
    k = nums.size() - k;
    while(lo < hi) {
      int j = partition(nums, lo, hi);
      if(j < k) {
        lo = j + 1;
      } else if(j > k) {
          hi = j - 1;
      } else {
        return nums[k];
      }
    }
    return nums[k];
  }
};
class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
=======
class Solution {

 public:
  int partition(vector<int> & nums, int lo, int hi) {
    int i = lo, j = hi + 1;
    while(1) {
      while(nums[++i] < nums[lo]) {
        if(i == hi) break;
      }
      while(nums[--j] > nums[lo]) {
        if(j == lo) break;
      }
      if(i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[lo], nums[j]);
    return j;
  }

  // O(N) with worst cast O(N*N)
  int findKthLargest(vector<int>& nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int lo = 0, hi = nums.size() - 1;
    k = nums.size() - k;
    while(lo < hi) {
      int j = partition(nums, lo, hi);
      if(j < k) {
        lo = j + 1;
      } else if(j > k) {
          hi = j - 1;
      } else {
        return nums[k];
      }
    }
    return nums[k];
  }
};
class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};