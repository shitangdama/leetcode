<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        prev, current = 0, 1
        for i in xrange(n):
            prev, current = current, prev + current, 
        return current

if __name__ == "__main__":
    result = Solution().climbStairs(2)
    print result
=======
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        prev, current = 0, 1
        for i in xrange(n):
            prev, current = current, prev + current, 
        return current

if __name__ == "__main__":
    result = Solution().climbStairs(2)
    print result
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
