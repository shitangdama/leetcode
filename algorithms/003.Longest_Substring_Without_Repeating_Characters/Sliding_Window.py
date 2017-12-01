class Solution:
    def lengthOfLongestSubstring(self, s):
        n = len(s)
        hash = {}
        i, j = 0, 0
        ans = 0
        while i < n and j < n:
            if s[j] in hash:
                del hash[s[i]]
                i =i + 1
            else:
                hash[s[j]] = j
                j = j + 1
                ans = max(ans, j - i)
        return ans