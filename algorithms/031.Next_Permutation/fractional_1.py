# 一个全排列问题,主要是先找最后一个逆序数，然后反转
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k = -1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] < nums[i+1]:
                k = i
                break
        print(k)
        if k == -1:
            nums.reverse()
            return
        l = -1
        for i in range(len(nums)-1, k, -1):
            if nums[i] > nums[k]:
                l = i
                break
        print(l)
        nums[l], nums[k] = nums[k], nums[l]
        self.reverse(nums,k+1,len(nums)-1)
    def reverse(self,nums,l,r):
        while l < r:
            nums[l],nums[r] = nums[r],nums[l]
            l += 1
            r -= 1

a=[1,3,2]
s= Solution()
s.nextPermutation(a)
print(a)