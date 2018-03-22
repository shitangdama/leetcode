class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        rs = [amount+1] * (amount+1)
        rs[0] = 0
        
        for c in coins:
            for i in range(1, amount+1):
                if i >= c:
                    rs[i] = min(rs[i], rs[i-c] + 1)

        if rs[amount] == amount+1:
            return -1
        return rs[amount]


s = Solution()
a = s.coinChange([243,291,335,209,177,345,114,91,313,331],7367)
print(a)