<<<<<<< HEAD
public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        return Math.max(helper(nums, 0, n-1), helper(nums, 1, n));
    }

    private int helper(int nums[], int inclusive, int exclusive){
        if(inclusive>=exclusive) return 0;
        int first = 0, second = nums[inclusive];
        for(int i=inclusive+1; i<exclusive; i++){
            int temp = second;
            second = Math.max(first+nums[i], temp);
            first = temp;
        }
        return second;
    }
}

=======
public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        return Math.max(helper(nums, 0, n-1), helper(nums, 1, n));
    }

    private int helper(int nums[], int inclusive, int exclusive){
        if(inclusive>=exclusive) return 0;
        int first = 0, second = nums[inclusive];
        for(int i=inclusive+1; i<exclusive; i++){
            int temp = second;
            second = Math.max(first+nums[i], temp);
            first = temp;
        }
        return second;
    }
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
