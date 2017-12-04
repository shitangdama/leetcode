class Solution:
    def longestPalindrome(self, s):
        start, end = 0, 0 
        for i in range(len(s)):
            len1 = self.expand_around_center(s, i, i)
            len2 = self.expand_around_center(s, i, i+1)
            len_max = max(len1, len2)
            if len_max>(end-start):
                start = i - int((len_max-1)/2)
                end = int(start + len_max)
                
        return s[start: end]
    def expand_around_center(self, s, left, right):
        l, r = left, right
        while l>=0 and r<len(s) and s[l]==s[r] and l<=r:
            l = l-1
            r = r+1
        return r - l - 1