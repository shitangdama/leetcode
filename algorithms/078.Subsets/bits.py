# 对于3个元素的集合，000表示一个元素都不选择，001表示选择第一个元素，101表示选择第一个和第三个元素
# 这个方法很有意思
class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # 首先是2^n-1
        nums.sort()
        result = []
        for i in range(1<<len(nums)):
            tmp = []
            for j in range(len(nums)):
                if ((1<<j) & i) != 0:
                    tmp.append(nums[j])
            result.append(tmp)
        return result
