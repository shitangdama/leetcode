class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        if x == 0:
            return 0
        l, r = 1, x/2 + 1
        while l <= r:
            m = (l + r) // 2
            if m <= x // m and x // (m + 1) < m + 1:
                return m
            if x // m < m:
                r = m - 1
            else:
                l = m + 1
        return 0

s = Solution()
print s.sqrt(16)

