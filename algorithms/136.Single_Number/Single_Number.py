import operator

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        return reduce(operator.xor, A)

if __name__ == '__main__':
    print Solution().singleNumber([1, 1, 2, 2, 3])
