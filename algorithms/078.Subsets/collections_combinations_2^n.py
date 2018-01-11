from itertools import *
class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        S.sort()
        res = []
        for i in range(len(S) + 1):
            res += list(list(x) for x in combinations(S, i))
        return res

