# Time:  O(m * n)
# Space: O(m + n)
#     1 1 1 1  1  1
#     1 2 3 4  5  6
#     1 3 6 10 15 21
# dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
# dp[i][j],dp[i-1][j] ---> dp[j]
# dp[i][j-1] ---> dp[j-1]
class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        if m < n:
            return self.uniquePaths(n, m)

        ways = [1] * n

        for i in range(1, m):
            for j in range(1, n):
                ways[j] += ways[j - 1]

        return ways[n - 1]

if __name__ == "__main__":
    prin(Solution().uniquePaths(1, 2))
