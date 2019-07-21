# class Solution:
    # def fourSum(self, nums, target):
    #     """
    #     :type nums: List[int]
    #     :type target: int
    #     :rtype: List[List[int]]
    #     """
    #     results = []
    #     self.find_n_sum(sorted(nums), target, 4, [], results)
    #     return results
        
    # def find_n_sum(self, nums, target, N, result, results):
    #     if len(nums) < N or N < 2 or target < nums[0]*N or target > nums[-1]*N:  # early termination
    #         return
    #     if N == 2:
    #         l,r = 0,len(nums)-1
    #         while l < r:
    #             s = nums[l] + nums[r]
    #             if s == target:
    #                 results.append(result + [nums[l], nums[r]])
    #                 l += 1
    #                 while l < r and nums[l] == nums[l-1]:
    #                     l += 1
    #             elif s < target:
    #                 l += 1
    #             else:
    #                 r -= 1
    #     else: # recursively reduce N
    #         for i in range(len(nums)-N+1):
    #             if i == 0 or (i > 0 and nums[i-1] != nums[i]):
    #                 self.find_n_sum(nums[i+1:], target-nums[i], N-1, result+[nums[i]], results)     
            

# s = Solution()
# a = s.fourSum([1,0,-1,0,-2,2],0)
# print(a)

class Solution:
    def fourSum(self, nums, target):
        result = []
        nums.sort()
        val_hash = {}
        
        if len(nums) < 4:
            return []
        
        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                val = nums[i] + nums[j]
                if val not in val_hash:
                    val_hash[val] = [[i,j]]
                else:
                    val_hash[val].append([i,j])

        for i in range(len(nums)):
            for j in range(i+1, len(nums)-2):
                diff=target-nums[i]-nums[j]

                if diff in val_hash:
                    for k in val_hash[diff]:
                        # 剪枝 旧的比新的index大
                        if k[0] > j and [nums[i], nums[j], nums[k[0]], nums[k[1]]] not in result:
                            result.append([nums[i], nums[j], nums[k[0]], nums[k[1]]])
        return result







        

