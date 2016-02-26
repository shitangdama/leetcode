# Time:  O(n)
# Space: O(1)

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        carry = 1
        for i in reversed(xrange(len(digits))):
            digits[i] += carry
            carry = digits[i] / 10
            digits[i] %= 10
        
        if carry:
            digits = [1] + digits
        
        return digits

if __name__ == "__main__":
    print Solution().plusOne([9, 9, 9, 9])
