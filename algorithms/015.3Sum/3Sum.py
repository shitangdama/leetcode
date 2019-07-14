# class Solution:
#     def threeSum(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[List[int]]
#         """
# #         首先是排序
#         nums = sorted(nums)
#         result = []
# #         有三个指针
#         i, j, k = 0, 1, len(nums) - 1
#         while i < len(nums) - 2:
# #             先判断jk
#             # 要更新jk
#             j = i+1
#             k = len(nums) - 1
#             while j < k:
# #                 判断怎么移动
#                 if nums[i] + nums[j] + nums[k] < 0:
#                     j = j + 1
#                 elif nums[i] + nums[j] + nums[k] > 0:
#                     k = k - 1
#                 else:
#     #               作为答案
#                     result.append([nums[i], nums[j], nums[k]])
#                     j, k = j+1, k-1
#     #               需要额外判断j和k是否是连号情况
#     #               意义是防止重复答案
#                     while j < k and nums[j] == nums[j-1]:
#                         j = j + 1
#                     while j < k and nums[k] == nums[k+1]:
#                         k = k - 1
                    
#             i = i+1
#             while  i < len(nums) - 2 and nums[i] == nums[i-1]:
#                 i = i+1
#         return result

# s = Solution()
# a = s.threeSum([-1,0,1,2,-1,-4])
# print(a)
