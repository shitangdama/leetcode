public class Solution {
    /**
     * @param heights: an array of integers
     * @return: an integer
     */
    int computeArea(int left, int right,  int[] heights) {
        return (right-left)*Math.min(heights[left], heights[right]);
    }
    
    public int maxArea(int[] heights) {
        // write your code here
        int left = 0, ans=  0 ; 
        int right = heights.length - 1;
        while(left <= right) {
            ans = Math.max(ans,computeArea(left, right, heights));
            if(heights[left]<=heights[right])
                left++;
            else
                right--;
        }
        return ans;
    }
}