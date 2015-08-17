class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        one, two = 0, 0
        for x in A:
            one, two = (~x & one) | (x & ~one & ~two), (~x & two) | (x & one)
        return one
        
class Solution2:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        one, two, carry = 0, 0, 0
        for x in A:
            two |= one & x
            one ^= x
            carry = one & two
            one &= ~carry
            two &= ~carry
        return one

#  every element appears 4 times except for one with 2 times
class SolutionEX:
    # @param A, a list of integer
    # @return an integer
    # [1, 1, 1, 1, 2, 2, 2, 2, 3, 3]
    def singleNumber(self, A):
        one, two, three = 0, 0, 0
        for x in A:
            one, two, three = (~x & one) | (x & ~one & ~two & ~three), (~x & two) | (x & one), (~x & three) | (x & two)
        return two

if __name__ == "__main__":
    print Solution().singleNumber([1, 1, 1, 2, 2, 2, 3])

