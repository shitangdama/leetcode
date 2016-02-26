class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):

        # define process function
        def proc(x):
            s = 0
            while x:
                s += (x % 10) ** 2
                x /= 10
            return s

        # loop
        a = proc(n)
        b = proc(a)
        while a != 1 and a != b:
            a = proc(a)
            b = proc(b)
            b = proc(b)

        return 1 == a

# debug
s = Solution()
print s.isHappy(19)
class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        lookup = {}
        while n != 1 and n not in lookup:
            lookup[n] = True
            n = self.nextNumber(n)
        return n == 1
    
    def nextNumber(self, n):
        new = 0
        for char in str(n):
            new += int(char)**2
        return new
