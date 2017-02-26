class Solution(object):
    def __init__(self):
        self._num = [0]
        
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = self._num
        while len(num) <= n:
            num += [min(num[-i*i] for i in range(1, int(len(num)**0.5+1))) + 1]
        return num[n]
