class Solution:
    def permuteUnique(self, nums):
        nums.sort()
        result = []
        tmp = []
        used = [0] * len(nums)
        self.dfs(result, used, [], nums)
        return result
        
    def dfs(self, result, used, tmp, nums):
        if len(tmp) == len(nums):
            result.append(list(tmp))
        else:
            for i in range(len(nums)):
                if used[i] != 1:
                    # 作用是上个是一样的，以加入数字和为加入数字是否相等，以加入时候哪里已经加入了一次
                    if used[i] !=1 and i > 0 and nums[i] == nums[i-1] and used[i-1] != 0:
                        continue
                    used[i] = 1
                    tmp.append(nums[i])
                    self.dfs(result, used, tmp, nums)
                    # 因为传参引用导致要把东西变回去
                    used[i] = 0
                    tmp.pop()

s = Solution()
print(s.permuteUnique([1,1,2]))