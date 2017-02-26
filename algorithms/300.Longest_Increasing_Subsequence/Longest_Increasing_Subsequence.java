<<<<<<< HEAD
public class Solution {
    public int lengthOfLIS(int[] nums) {            
        int[] dp = new int[nums.length];
        int len = 0;

        for(int x : nums) {
            int i = Arrays.binarySearch(dp, 0, len, x);
            if(i < 0) i = -(i + 1);
            dp[i] = x;
            if(i == len) len++;
        }

        return len;
    }
}
public int lengthOfLIS(int[] nums) {
    ArrayList<Integer> dp = new ArrayList<>(nums.length);
    for (int num : nums) {
        if (dp.size() == 0 || dp.get(dp.size()-1) < num) dp.add(num);
        else {
            int i = Collections.binarySearch(dp, num);
            dp.set((i<0) ? -i-1 : i, num);
        }
    }
    return dp.size();
=======
public class Solution {
    public int lengthOfLIS(int[] nums) {            
        int[] dp = new int[nums.length];
        int len = 0;

        for(int x : nums) {
            int i = Arrays.binarySearch(dp, 0, len, x);
            if(i < 0) i = -(i + 1);
            dp[i] = x;
            if(i == len) len++;
        }

        return len;
    }
}
public int lengthOfLIS(int[] nums) {
    ArrayList<Integer> dp = new ArrayList<>(nums.length);
    for (int num : nums) {
        if (dp.size() == 0 || dp.get(dp.size()-1) < num) dp.add(num);
        else {
            int i = Collections.binarySearch(dp, num);
            dp.set((i<0) ? -i-1 : i, num);
        }
    }
    return dp.size();
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}