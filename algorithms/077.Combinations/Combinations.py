# Time:  O(n!)
# Space: O(n)

class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        result = []
        self.combineRecu(n, result, 0, [], k)
        return result
    
    def combineRecu(self, n, result, start, intermediate, k):
        if k == 0:
            result.append(intermediate[:])
        for i in xrange(start, n):
            intermediate.append(i + 1)
            self.combineRecu(n, result, i + 1, intermediate, k - 1)
            intermediate.pop()

if __name__ == "__main__":
    result = Solution().combine(4, 2)
    print result
