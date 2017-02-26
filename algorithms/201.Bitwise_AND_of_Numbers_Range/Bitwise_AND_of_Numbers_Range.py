import math

class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        if m == n:
            return m
        move = int(math.log(n - m) / math.log(2)) + 1
        m >>= move
        n >>= move
        return (n&m) << move

# debug
s = Solution()
print s.rangeBitwiseAnd(5, 7)

class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        while m < n:
            n &= n - 1
        return n

class Solution2:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        i, diff = 0, n-m
        while diff:
            diff >>= 1
            i += 1
        return n&m >> i << i

if __name__ == '__main__':
    print Solution().rangeBitwiseAnd(5, 7)
