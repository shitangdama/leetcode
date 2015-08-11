# Time:  O(n^2)
# Space: O(n)

import math

# Cantor ordering solution
class Solution:
    # @return a string
    def getPermutation(self, n, k):
        seq, k, fact = "", k - 1, math.factorial(n - 1)
        perm = [i for i in xrange(1, n + 1)]
        for i in reversed(xrange(n)):
            curr = perm[k / fact]
            seq += str(curr)
            perm.remove(curr)
            if i > 0:
                k %= fact
                fact /= i
        return seq
    
class Solution:
    """
    @param n: n
    @param k: the k-th permutation
    @return: the k-th permutation
    """
    def getPermutation(self, n, k):
        fac = [1]
        for i in range(1, n + 1):
            fac.append(fac[-1] * i)
        
        elegible = range(1, n + 1)
        per = []
        for i in range(n):
            digit = (k - 1) / fac[n - i - 1]
            per.append(elegible[digit])
            elegible.remove(elegible[digit])
            k = (k - 1) % fac[n - i - 1] + 1
        return "".join([str(x) for x in per])




if __name__ == "__main__":
    print Solution().getPermutation(3, 2)
