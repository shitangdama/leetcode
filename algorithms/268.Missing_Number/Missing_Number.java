public class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;

        return (nums.length * (nums.length + 1) )/ 2 - sum;
    }
}
public class Solution {
    public int missingNumber(int[] nums) {
    int sum = 0;
    for (int i = 0; i <= nums.length; ++i) sum ^= i;
    for (int i = 0; i < nums.length; ++i) sum ^= nums[i];
    return sum;
}
}
1.XOR

public int missingNumber(int[] nums) { //xor
    int res = nums.length;
    for(int i=0; i<nums.length; i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

2.SUM

public int missingNumber(int[] nums) { //sum
    int len = nums.length;
    int sum = (0+len)*(len+1)/2;
    for(int i=0; i<len; i++)
        sum-=nums[i];
    return sum;
}

3.Binary Search

public int missingNumber(int[] nums) { //binary search
    Arrays.sort(nums);
    int left = 0, right = nums.length, mid= (left + right)/2;
    while(left<right){
        mid = (left + right)/2;
        if(nums[mid]>mid) right = mid;
        else left = mid+1;
    }
    return left;
}

Summary:

If the array is in order, I prefer Binary Search method. Otherwise, the XOR method is better.