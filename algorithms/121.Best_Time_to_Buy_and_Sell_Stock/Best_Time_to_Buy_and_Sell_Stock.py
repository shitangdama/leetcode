class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices:
            return 0
        buy_price, profit = prices[0], 0
        for price in prices:
            buy_price = min(buy_price, price)
            profit = max(profit, price - buy_price)
        return profit
class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        max_profit, min_price = 0, float("inf")
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)  
        return max_profit

if __name__ == "__main__":
    result = Solution().maxProfit([3, 2, 1, 4, 2, 5, 6])
    print result

# debug
s = Solution()
print s.maxProfit([])
