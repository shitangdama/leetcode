class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        candidates.sort()
        
        self.dfs(result, target, candidates, [], 0)
        return result

# 这里的n是在candidates中的位数，防止重复答案出现，只能从n位后面的数字选取
    def dfs(self, result, remain, candidates, tmp, n):
        if remain < 0:
            return
        elif remain == 0:
            result.append(list(tmp))
        else:
            for i in range(n, len(candidates)):
                tmp.append(candidates[i])
                # 这里注意最后一位i，不是传统的n+1,而是使用当前迭代数字i，为了重复使用数字
                self.dfs(result, remain-candidates[i], candidates, tmp, i)
                tmp.pop()

s = Solution()
a = s.combinationSum([2,3,6,7], 7)
print(a)