class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n):
            if dp[i]:
                for word in dict:
                    j = len(word)
                    if i + j <= n and s[i: i + j] == word:
                        dp[i + j] = True
        return dp[n]

# debug
s = Solution()
print s.wordBreak('a', ['a'])
class Solution:
    # @param s: A string s
    # @param dict: A dictionary of words dict
    def wordSegmentation(self, s, dict):
        if not s:
            return True
            
        cnt = {}
        for w in dict:
            for c in w:
                if c not in cnt:
                    cnt[c] = 0
                cnt[c] += 1
        for c in s:
            if c not in cnt:
                return False
                
        n = len(s)
        possible = [False for _ in xrange(n)]
        for i in xrange(n):
            for j in reversed(xrange(i + 1)):
                if (j == 0 or possible[j-1]) and s[j:i+1] in dict:
                    possible[i] = True
                    break
                
        return possible[n-1]

# slower
class Solution2:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        n = len(s)
        possible = [False for _ in xrange(n)]
        for i in xrange(n):
            if s[:i+1] in dict:
                possible[i] = True
            for j in xrange(i):
                if possible[j] and s[j+1:i+1] in dict:
                    possible[i] = True
                    break
                
        return possible[n-1]
    
if __name__ == "__main__":
    print Solution().wordBreak("leetcode", ["leet", "code"])
