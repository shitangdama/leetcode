class Solution:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        k %= len(nums)
        self.reverse(nums, 0, len(nums))
        self.reverse(nums, 0, k)
        self.reverse(nums, k, len(nums))
    
    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end-1] = nums[end-1], nums[start]
            start += 1
            end -= 1

from fractions import gcd

class Solution2:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        k %= len(nums)
        num_cycles = gcd(len(nums), k)
        cycle_len = len(nums) / num_cycles
        for i in xrange(num_cycles):
            self.apply_cycle_permutation(k, i, cycle_len, nums)
    
    def apply_cycle_permutation(self, k, offset, cycle_len, nums):
        tmp = nums[offset]
        for i in xrange(1, cycle_len):
            nums[(offset+i*k) % len(nums)], tmp = tmp, nums[(offset+i*k) % len(nums)]
        nums[offset] = tmp
          
if __name__ == '__main__':
    nums = [1,2,3,4,5,6,7]
    Solution().rotate(nums, 3)
    print nums

