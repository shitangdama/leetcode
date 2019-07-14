class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = [-1, -1]
        num_h = {}
        
        for index in range(len(nums)):
            if (target - nums[index]) in num_h:
                result = [index, num_h[target - nums[index]]]    
            num_h[nums[index]] = index
        
        return result