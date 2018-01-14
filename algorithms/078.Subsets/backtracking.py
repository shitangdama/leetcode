class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    # def subsets(self, S):
    def subsets(self, nums):
        res = []
        nums.sort()
        self.backtracking(nums, 0, [], res)
        return res
    
    def backtracking(self, nums, index, path, res):

        res.append(path)
        for i in range(index, len(nums)):
            # if i > index and nums[i] == nums[i-1]:
            #     continue
            print(222222222222)
            self.backtracking(nums, i+1, path+[nums[i]], res)

s = Solution()
print(s.subsets([1,2,3]))