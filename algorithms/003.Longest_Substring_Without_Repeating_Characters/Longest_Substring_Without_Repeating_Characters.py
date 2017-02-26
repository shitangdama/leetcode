<<<<<<< HEAD
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
=======
# Time:  O(n^2)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLongestSubstringTwoDistinct(self, s):
        longest, start, distinct_count, visited = 0, 0, 0, [0 for _ in xrange(256)]
        for i, char in enumerate(s):
            if visited[ord(char)] == 0:
                distinct_count += 1
            visited[ord(char)] += 1
            
            while distinct_count > 2:
                visited[ord(s[start])] -= 1
                if visited[ord(s[start])] == 0:
                    distinct_count -= 1
                start += 1
  
            longest = max(longest, i - start + 1)
        return longest
    
if __name__ == "__main__":
    print Solution().lengthOfLongestSubstringTwoDistinct("eceba")
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
