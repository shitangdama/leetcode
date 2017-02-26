# Time:  O(n * 2^n)
# Space: O(1)

class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        result = []
        i, count = 0, 1 << len(S)
        S = sorted(S)
        
        while i < count:
            cur = []
            for j in xrange(len(S)):
                if i & 1 << j:
                    cur.append(S[j])
            result.append(cur)
            i += 1
            
        return result

class Solution2:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        return self.subsetsRecu([], sorted(S))
    
    def subsetsRecu(self, cur, S):
        if not S:
            return [cur]
        
        return self.subsetsRecu(cur, S[1:]) + self.subsetsRecu(cur + [S[0]], S[1:])
        
if __name__ == "__main__":
    print Solution().subsets([1, 2, 3])
