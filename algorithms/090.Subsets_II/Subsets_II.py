from itertools import groupby
class Solution:
    def dfs(self, dep, newS):
        if dep == len(newS):
            self.res.append(self.cur[:])
        else:
            self.dfs(dep + 1, newS)
            for i in newS[dep]:
                self.cur.append(i)
                self.dfs(dep + 1, newS)
            for i in newS[dep]:
                self.cur.pop()

    # @param S, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        S.sort()
        newS = [list(g) for k, g in groupby(S)]
        self.res = []
        self.cur = []
        self.dfs(0, newS)
        return self.res

# debug
s = Solution()
# print s.subsetsWithDup([1, 2, 2])


