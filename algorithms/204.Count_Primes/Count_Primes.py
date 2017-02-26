from math import sqrt

class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0
        
        is_prime = [True] * n
        sqr = sqrt(n - 1)
        
        num = 0
        for i in xrange(2, n):
            if is_prime[i]:
               num += 1
               for j in xrange(i+i, n, i):
                   is_prime[j] = False
                   
        return num

