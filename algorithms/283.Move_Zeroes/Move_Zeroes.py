<<<<<<< HEAD
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort(cmp= lambda a, b: -1 if b == 0 else 0)
=======
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort(cmp= lambda a, b: -1 if b == 0 else 0)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
