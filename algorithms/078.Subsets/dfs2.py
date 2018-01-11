# 简化版dfs
class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        return self.subsetsRecu([], sorted(S))
    
    def subsetsRecu(self, cur, S):
        if not S:
            return [cur]
            # 左面是没有选，右面是选了
        return self.subsetsRecu(cur, S[1:]) + self.subsetsRecu(cur + [S[0]], S[1:])