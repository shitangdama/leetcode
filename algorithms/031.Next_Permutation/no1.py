# 一个全排列问题,主要是先找最后一个逆序数，然后反转
# 字典序
# 这个题不需要返回值
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k = -1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] <= nums[i+1]:
                k = i
                break
        
        if k == -1:
            self.reverse(nums , 0, len(nums)-1)
            
        l = -1
        for i in range(len(nums)-1, k, -1):
            if nums[i] > nums[k]:
                l = i
                break
        

        nums[l], nums[k] = nums[k], nums[l]

        self.reverse(nums, k+1, len(nums)-1)

    def reverse(self, num, l, r):
        while l < r:
            num[l],num[r] = num[r],num[l]
            l += 1
            r -= 1

a=[1,3,2]
s= Solution()
s.nextPermutation(a)
print(a)