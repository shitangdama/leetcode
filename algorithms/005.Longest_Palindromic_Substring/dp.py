# Dynamic Programming
# O(n^2)， dp[i][j] = dp[i + 1][j - 1] (if s[i] == s[j])

def longestPalindrome(self, s):
    """
    :type s: str
    :rtype: str
    """
    if len(s) == 0:
        return s
    if len(set(s)) == 1: 
        return s
    
    n = len(s)
    left = 0
    right = 0
    maxLen = 0
    dp = [[0 for _ in range(n)] for _ in range(n)]
    
    for i in range(n):            
        for j in range(i):
            if s[j] == s[i]:
                if (i - j == 1) or dp[j + 1][i - 1] == 1:
                    dp[j][i] = 1
        
            if dp[j][i] == 1 and maxLen < i - j + 1:
                maxLen = i - j + 1
                left = j
                right = i
        
        dp[i][i] = 1
    
    return s[left : right + 1]