class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        i = 0 
        
        min_diff = 99
        result = 99
        
        while i < len(nums) - 2:
            j, k = i+1, len(nums)-1
            
            while j < k:
                diff = nums[i] + nums[j] + nums[k] - target
                if abs(diff) < min_diff:
                    min_diff = abs(diff)
                    result = nums[i] + nums[j] + nums[k]
                if diff < 0:
                    j = j + 1
                elif diff > 0:
                    k = k - 1
                else:
                    return result
            
            i = i + 1
            while  i < len(nums) - 2 and nums[i] == nums[i-1]:
                i = i+1
        return result

s = Solution()
a = s.threeSumClosest([1,1,-1,-1,3], -1)
print(a)