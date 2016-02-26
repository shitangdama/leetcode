class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        ans = 0
        while n:
            ans += n // 5
            n //= 5
        return ans

# debug
s = Solution()
print s.trailingZeroes(5)

