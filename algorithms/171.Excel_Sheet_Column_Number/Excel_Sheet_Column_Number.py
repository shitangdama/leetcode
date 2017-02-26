class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        return reduce(lambda x, y: 26 * x + ord(y) - ord('A') + 1, s, 0)

# debug
s = Solution()
print s.titleToNumber('AA')



class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        result = 0
        for i in xrange(len(s)):
            result *= 26
            result += ord(s[i]) - ord('A') + 1
        return result

if __name__ == "__main__":
    print Solution().titleToNumber("AAAB")
