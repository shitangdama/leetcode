# 迭代方法

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        res = [[]]
        S.sort()
        for i in range(len(S)):
            # if i == 0 or S[i] != S[i - 1]:
            l = len(res)
            for j in range(len(res) - l, len(res)):
                print(res[j] + [S[i]])
                res.append(res[j] + [S[i]])
        return res

s = Solution()

print(s.subsets([1,2,3]))