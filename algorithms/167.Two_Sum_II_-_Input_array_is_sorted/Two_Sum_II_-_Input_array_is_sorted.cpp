<<<<<<< HEAD
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// O(n) time, O(1) space
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int s = 0, e = numbers.size() - 1;
    while(s < e) {
      int v = numbers[s] + numbers[e];
      if(v == target) {
        result.push_back(s+1);
        result.push_back(e+1);
        return result;
      }
      else if(v < target) {
        s += 1;
      }
      else {
        e -= 1;
      }
    }
  }
=======
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// O(n) time, O(1) space
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int s = 0, e = numbers.size() - 1;
    while(s < e) {
      int v = numbers[s] + numbers[e];
      if(v == target) {
        result.push_back(s+1);
        result.push_back(e+1);
        return result;
      }
      else if(v < target) {
        s += 1;
      }
      else {
        e -= 1;
      }
    }
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};