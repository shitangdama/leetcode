class Solution:
    def reverse(self, x):
        ans = 0
        if x >= 0:
            while x:
                ans = ans * 10 + x % 10
                x = int(x/10)
            return ans if ans <= 2147483647 else 0  # Handle overflow.
        else:
            return -self.reverse(-x)