class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        result = []
        self.dfs(result, nums, [], 0, [])
        return result
# 
    def dfs(self, result, nums, tmp, tmp_len, no_tmp):
        # pass
        if len(nums) == tmp_len:
            new_tmp = list(tmp)
            result.append(new_tmp)
            while len(no_tmp) != 0:
                no_tmp.pop()
        else:
            # 选择某一个数
            tmp.append(nums[tmp_len])
                
            if nums[tmp_len] not in no_tmp:
                self.dfs(result, nums, tmp, tmp_len+1, no_tmp)
            # 不选某个数
            no_num = tmp.pop()
            if no_num not in no_tmp:
                no_tmp.append(no_num)

            # if tmp_len == 0:
            #     no_tmp = []
            self.dfs(result, nums, tmp, tmp_len+1, no_tmp)

s = Solution()
print(s.subsetsWithDup([1,2,2]))