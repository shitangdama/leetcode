import java.util.*

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int[] flag = new int[128];
        for (int i = 0; i < flag.length; i++) {
            flag[i] = -1;
        }
        // left and right pointer defines the valid range
        int left = 0;
        int right = 0;
        int longest = 0;
        int len = s.length();

        while (right < len) {
            char letter = s.charAt(right);
            int previousPos = flag[letter];
            if (previousPos != -1&& previousPos >= left) {
                // if right pointer points to an old letter, and is within current range
                // then we need to update our left pointer: 
                // to bypass the previous occurrence of that letter
                left = previousPos + 1;
            }
            flag[letter] = right;
            // advance right pointer to the next letter, and calculate longest distance
            right++;
            longest = Math.max(longest, right - left);
        }
        return longest;
    }
}
