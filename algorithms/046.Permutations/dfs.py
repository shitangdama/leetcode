class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
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
                    used[i] = 1
                    tmp.append(nums[i])
                    self.dfs(result, used, tmp, nums)
                    # 因为传参引用导致要把东西变回去
                    used[i] = 0
                    tmp.pop()

                #     ArrayUtils.swap(array, cursor, i);
                # fullArray(array, cursor + 1, end);
                # ArrayUtils.swap(array, cursor, i); // 用于对之前交换过的数据进行还原
                # 这样也可以，就是使用一个n标签

s = Solution()
print(s.permute([1,2,3]))
