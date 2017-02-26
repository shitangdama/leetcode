class Solution(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if not n or not k:
            return 0
        if n == 1:
            return k
        dp = [0] * (n+1)
        dp[1] = k
        dp[2] = k*(k-1) + k
        for i in range(3, n+1):
            dp[i] = (dp[i-1]+dp[i-2]) * (k - 1)
        return dp[-1]
