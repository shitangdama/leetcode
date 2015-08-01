import java.util.*

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int len = s.length();
        int left = 0;
        int right = 1;
        HashSet<Character> set = new HashSet<Character>();
        set.add(s.charAt(0));
        int longest = 1;
        while (right < len) {
            // right pointer proceeds until boundary or duplicate char found
            while (right < len && !set.contains(s.charAt(right))) {
                set.add(s.charAt(right));
                right++;
                longest = Math.max(longest, right - left);
            }
            if (right == len) {
                return longest;
            } else {
                // right pointer has reached a duplicate char.
                // now move left pointer until that dup char is found
                while (s.charAt(left) != s.charAt(right)) {
                    set.remove(s.charAt(left));
                    left++;
                }
                // left pointer advance by one to bypass the dup char
                left++;
                // right pointer advance by one to include the dup char
                right++;
            }
        }
        return Math.max(longest, right - left);
    }
}
