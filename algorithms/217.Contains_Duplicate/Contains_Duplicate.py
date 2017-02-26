class Solution:
    def containDuplicate(self, nums):
        return len(set(nums)) != len(nums)

s = Solution()
print(s.containDuplicate([1, 2, 3, 4]))
print(s.containDuplicate([2, 2, 3, 4]))
class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        return len(nums) > len(set(nums))
