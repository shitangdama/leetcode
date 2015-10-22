class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        comp = lambda a, b: -1 if a + b > b + a else 1 if a + b < b + a else 0
        return str(int("".join(sorted(map(str, num), comp))))

# debug
s = Solution()
print s.largestNumber([0, 0, 5])
