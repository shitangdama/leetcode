class Solution:
    def threeSum(self, nums):
        nums.sort()
        print(nums)
        i, j, k = 0, 1, len(nums) - 1
        result = []
        while i < len(nums) - 2:
            j = i + 1
            k = len(nums) - 1
            
            while j < k:
                if nums[i] + nums[j] + nums[k] > 0:
                    k = k - 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j = j + 1
                else:
                    result.append([nums[i], nums[j], nums[k]])
                    j,k = j+1,k-1
                    
                    while j<k and nums[j]==nums[j-1]:
                        j = j + 1 
                    while j<k and nums[k]==nums[k+1]:
                        k = k - 1
            i = i + 1
            while i < len(nums) - 2 and nums[i]==nums[i-1]:
                i = i + 1
        return result

s = Solution()
a = s.threeSum([-1,0,1,2,-1,-4])
print(a)
