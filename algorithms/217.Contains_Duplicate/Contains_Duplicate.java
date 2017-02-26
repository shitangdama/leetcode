<<<<<<< HEAD
public class Solution {
  public boolean containsDuplicate(int[] nums) {
    if (nums == null || nums.length == 0) {
      return false;
    }

    HashSet<Integer> map = new HashSet<>();
    for (int i = 0; i < nums.length; i++) {
      if (map.contains(nums[i])) {
        return true;
      }
      map.add(nums[i]);
    }

    return false;
  }
=======
public class Solution {
  public boolean containsDuplicate(int[] nums) {
    if (nums == null || nums.length == 0) {
      return false;
    }

    HashSet<Integer> map = new HashSet<>();
    for (int i = 0; i < nums.length; i++) {
      if (map.contains(nums[i])) {
        return true;
      }
      map.add(nums[i]);
    }

    return false;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}