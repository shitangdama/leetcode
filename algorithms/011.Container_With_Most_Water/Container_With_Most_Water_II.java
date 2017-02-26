public class Solution {
    // for any i, the maxium area will be the farthest j that has a[j] > a[i];
    public int maxArea(int[] height) {
        if(height == null || height.length < 2) {
            return 0;
        }
        int max = 0;
        int left = 0;
        int right = height.length -1;
        while(left < right) {
            max = Math.max( max, (right - left) * Math.min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return max;
        
    }
}