# 滑动窗口，动态规划
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        charMap = {}
        tmp = 0
        for i,char in enumerate(s):
            if charMap.has_key(char):
                tmp = max(charMap[char],tmp)
            ans = max(ans,i-tmp+1)
            charMap[char] = i+1
        return ans