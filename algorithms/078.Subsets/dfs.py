import copy

class Solution:
    def subsets(self, nums):
        nums.sort()
        result = []
        self.dfs(result, nums, [], 0)
        return result
# 
    def dfs(self, result, nums, tmp, tmp_len):
        # pass
        if len(nums) == tmp_len:
            # 这里要进行深拷贝,不然下面的tmp.pop会影响这里的数据
            new_tmp = copy.copy(tmp)
            result.append(new_tmp)

        else:
            # 选择某一个数
            tmp.append(nums[tmp_len])
            self.dfs(result, nums, tmp, tmp_len+1)
            # 不选某个数
            tmp.pop()
            self.dfs(result, nums, tmp, tmp_len+1)


s = Solution()
a = s.subsets([1])
print(a)

# 制定前缀
# 原理是挨个选择，往左是选，往右是不选
#                      []        
#               /             \
#            [1]                []
#          /     \             /   \        
#     [1 2]       [1]       [2]     []
#    /     \     /   \     /   \    / \
# [1 2 2] [1 2]  X   [1]  [2 2] [2] X  []

# 这里面使用了一个stack
# 问题是使用占位是否和stack一个作用，是否出现[1,1]情况