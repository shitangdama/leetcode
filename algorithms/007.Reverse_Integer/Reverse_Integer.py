# Time: O(logn)
# Space: O(1)

class Solution:
    # @return an integer
    def reverse(self, x):
        ans = 0
        if x >= 0:
            while x:
                ans = ans * 10 + x % 10
                x /= 10
            return ans if ans <= 2147483647 else 0  # Handle overflow.
        else:
            return -self.reverse(-x)
        
if __name__ == "__main__":
    print Solution().reverse(123)
    print Solution().reverse(-321)
