public class 3SumSmaller {
    public int threeSumSmaller(int[] nums, int target) {
        if(nums.length<1) return 0;
        Arrays.sort(nums);
        int sum = 0;
        for(int i = 0 ; i < nums.length-2; i++){
            int low = i+1, high = nums.length-1;
            while(low < high){
                if(nums[i]+nums[low]+nums[high]>=target){
                    high--;
                }
                else {
                    sum += high-low;
                    low++;
                }
            }
        }
        return sum;
    }
}