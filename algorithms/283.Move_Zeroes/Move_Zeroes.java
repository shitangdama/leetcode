<<<<<<< HEAD
public class Solution {    

    public void moveZeroes(int[] nums) {
        int z = -1;
        for (int i=0; i< nums.length; i++) {
            int temp = nums[i];
            if (temp != 0) {
                nums[i]=nums[++z];
                nums[z]=temp;
            }
        }
    }

=======
public class Solution {    

    public void moveZeroes(int[] nums) {
        int z = -1;
        for (int i=0; i< nums.length; i++) {
            int temp = nums[i];
            if (temp != 0) {
                nums[i]=nums[++z];
                nums[z]=temp;
            }
        }
    }

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}