<<<<<<< HEAD
class Solution {
 public:
  // O(n) solution
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int sum = 0, sz = 0, start = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sz += 1;
      while(sum >= s) {
        result = min(result, sz);
          sum -= nums[start];
          start ++;
          sz -= 1;
        }
    }
    return result == INT_MAX ? 0 : result;
  }

  // O(nlogn) solution
  int minSubArrayLen2(int s, vector<int>& nums) {
    // TODO
  }

  int searchInsert(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1, m;
    while(s <= e) {
      m = s + (e - s) / 2;
      if(nums[m] == target) {
        return m;
      } else if(nums[m] < target) {
        s = m + 1;
      } else {
        e = m - 1;
      }
    }
    return nums[m] > target ? m : m + 1;
  }
};
class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums) {
    int firstPos = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minLength = min(minLength, i - firstPos + 1);
            sum -= nums[firstPos++];
        }
    }

    return minLength == INT_MAX? 0 : minLength;
  }
=======
class Solution {
 public:
  // O(n) solution
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int sum = 0, sz = 0, start = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sz += 1;
      while(sum >= s) {
        result = min(result, sz);
          sum -= nums[start];
          start ++;
          sz -= 1;
        }
    }
    return result == INT_MAX ? 0 : result;
  }

  // O(nlogn) solution
  int minSubArrayLen2(int s, vector<int>& nums) {
    // TODO
  }

  int searchInsert(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1, m;
    while(s <= e) {
      m = s + (e - s) / 2;
      if(nums[m] == target) {
        return m;
      } else if(nums[m] < target) {
        s = m + 1;
      } else {
        e = m - 1;
      }
    }
    return nums[m] > target ? m : m + 1;
  }
};
class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums) {
    int firstPos = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minLength = min(minLength, i - firstPos + 1);
            sum -= nums[firstPos++];
        }
    }

    return minLength == INT_MAX? 0 : minLength;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};