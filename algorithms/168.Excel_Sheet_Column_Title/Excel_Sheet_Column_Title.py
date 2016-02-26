class Solution:
    # @return a string
    def convertToTitle(self, num):
        ret = []
        while num > 0:
            ret += chr(ord('A') + (num - 1) % 26)
            num = (num - 1) // 26
        ret.reverse()
        return ''.join(ret)

# debug
s = Solution()
print s.convertToTitle(29)

class Solution:
    # @return a string
    def convertToTitle(self, num):
        result, dvd = "", num
        
        while dvd:
            result += chr((dvd - 1) % 26 + ord('A'))
            dvd = (dvd - 1) / 26
        
        return result[::-1]
        
if __name__ == "__main__":
    for i in xrange(1, 29):
        print Solution().convertToTitle(i)
