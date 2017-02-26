<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)
class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        result, carry, val, len_a, len_b, i = "", 0, 0, len(a), len(b), 0
        for i in xrange(max(len_a, len_b)):
            val = carry
            if i < len_a:
                sum += int(a[-(i + 1)])
            if i < len_b: 
                sum += int(b[-(i + 1)])
            carry, val = val / 2, val % 2
            result = "{0}{1}".format(val, result)
        if carry == 1:
            result = "1" + result
        return result

if __name__ == '__main__':
    result = Solution().addBinary('11', '1')
    print result
=======
# Time:  O(n)
# Space: O(1)
class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        result, carry, val, len_a, len_b, i = "", 0, 0, len(a), len(b), 0
        for i in xrange(max(len_a, len_b)):
            val = carry
            if i < len_a:
                sum += int(a[-(i + 1)])
            if i < len_b: 
                sum += int(b[-(i + 1)])
            carry, val = val / 2, val % 2
            result = "{0}{1}".format(val, result)
        if carry == 1:
            result = "1" + result
        return result

if __name__ == '__main__':
    result = Solution().addBinary('11', '1')
    print result
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
