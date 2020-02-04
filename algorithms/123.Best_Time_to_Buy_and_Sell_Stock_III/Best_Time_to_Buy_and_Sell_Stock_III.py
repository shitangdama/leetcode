class Solution:
    def maxProfit(self, prices):
        buy1, buy2 = -(1<<31), -(1<<31)
        sell1, sell2 = 0, 0

        for i in prices:
            sell2 = max(sell2, buy2 + i)    # max money after sell 2
            buy2 = max(buy2, sell1 - i)     # max money after buy 2
            sell1 = max(sell1, buy1 + i)    # max money after sell 1
            buy1 = max(buy1, -i)            # max money after buy 1

        return sell2


# 1.dp
# 交易两次
class Solution2:
    def maxProfit(self, prices):
        if not prices:
            return 0
        n = len(prices)
        # 初始化状态
        dp = [[[0]*2 for _ in range(3)] for _ in range(n)]
        for k in range(3):
            dp[0][k][1] = -prices[0]
        # 从 i=1 处开始迭代
        for i in range(1, n):
            for k in range(1, 3):
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
        return dp[n-1][2][0]


class Solution2:
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        dp = [[0] * (len(prices)) for _ in range(3)]

        for i in range(1,3):
            for j in range(1, len(prices)):
                profit = 0
                for m in range(j):
                    profit = max(profit, dp[i-1][m]+prices[j]-prices[m])
                dp[i][j] = max(dp[i][j-1], profit)

        return dp[-1][-1]


if __name__ == "__main__":
    result = Solution2().maxProfit([3, 2, 1, 4, 2, 5, 6])
    print(result)
