public class LongestSubstringWithAtMostTwoDistinctCharacters {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int i = 0, j = -1;
        int maxl = 0;
        for (int k = 1; k < s.length(); k++) {
            if (s.charAt(k) == s.charAt(k - 1)) continue;
            if (j >= 0 && s.charAt(k) != s.charAt(j)) {
                maxl = Math.max(maxl, k - i);
                i = j + 1;
            }
            j = k - 1;
        }
        return maxl;
    }
}
public class LongestSubstringWithoutRepeatingCharacters {
	/* Two pointer:
	 * #TwoSumII #ContainerWithMostWater
	 * #ContainerWithMostWater
	 * #LongestSubstringWithAtMostTwoDistinctCharacters
	 * #MaximumRangeNumber
	 * */
	public int lengthOfLongestSubstring(String s){
		int[] exist = new int[256];
		Arrays.fill(exist, -1);
		int maxLen = 0, start=0;
		
		for(int cur=0; cur<s.length(); cur++){
			if (exist[s.charAt(cur)] >= start)	start = exist[s.charAt(cur)]+1;
			else maxLen = Math.max(cur-start+1, maxLen);
			exist[s.charAt(cur)] = cur;
		}
		return maxLen;
	}
}