// For detailed explanation, see http://discuss.leetcode.com/questions/222/wildcard-matching

// Time: O(|s||p|*log|s|), Space: O(|s|)
// Time can also optimize to O(|s||p|)

public class Solution {

public boolean isMatch(String s, String p) {
    // without this optimization, it will fail for large data set
    int plenNoStar = 0;
    for (char c : p.toCharArray())
        if (c != '*') plenNoStar++;
    if (plenNoStar > s.length()) return false;

    s = " " + s;
    p = " " + p;
    int slen = s.length();
    int plen = p.length();

    boolean[] dp = new boolean[slen];
    TreeSet<Integer> firstTrueSet = new TreeSet<Integer>();
    firstTrueSet.add(0);
    dp[0] = true;

    boolean allStar = true;
    for (int pi = 1; pi < plen; pi++) {
        if (p.charAt(pi) != '*')
            allStar = false;
        for (int si = slen - 1; si >= 0; si--) {
            if (si == 0) {
                dp[si] = allStar ? true : false;
            } else if (p.charAt(pi) != '*') {
                if (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '?') dp[si] = dp[si-1];
                else dp[si] = false;
            } else {
                int firstTruePos = firstTrueSet.isEmpty() ? Integer.MAX_VALUE : firstTrueSet.first();
                if (si >= firstTruePos) dp[si] = true;
                else dp[si] = false;
            }
            if (dp[si]) firstTrueSet.add(si);
            else firstTrueSet.remove(si);
        }
    }
    return dp[slen - 1];
}
}