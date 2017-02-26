class Solution:
    # @return a list of integers
    def grayCode(self, n):
        return map(lambda x: x^(x>>1), xrange(1<<n))
        
# debug
s = Solution()
print s.grayCode(3)

class Solution2:
    # @param {int} n a number
    # @return {int[]} Gray code
    def grayCode(self, n):
        if n == 0:
            return [0]
        
        result = self.grayCode(n - 1)
        seq = list(result)
        for i in reversed(result):
            seq.append((1 << (n - 1)) | i)
            
        return seq
