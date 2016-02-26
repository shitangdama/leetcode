class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        res = '1'
        for _ in xrange(n - 1):
            res = self.helper(res)
        return res

    def helper(self, s):
        cnt, res = 1, ''
        for i in xrange(len(s) - 1):
            if s[i] == s[i + 1]:
                cnt += 1
            else:
                res += str(cnt) + s[i]
                cnt = 1
        res += str(cnt) + s[-1]
        return res

# test
s = Solution()
print(s.countAndSay(4))
