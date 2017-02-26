<<<<<<< HEAD
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.accu = [0]
        for num in nums: 
            self.accu += self.accu[-1] + num,

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int 
        :type j: int
        :rtype: int 
        """
        return self.accu[j + 1] - self.accu[i]


# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)
class NumArray(object):
    def __init__(self, nums):
        self.nums = nums + [0]
        for i in xrange(len(self.nums)-2, -1, -1):
            self.nums[i] += self.nums[i+1]

    def sumRange(self, i, j):
        return self.nums[i] - self.nums[j+1]
=======
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.accu = [0]
        for num in nums: 
            self.accu += self.accu[-1] + num,

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int 
        :type j: int
        :rtype: int 
        """
        return self.accu[j + 1] - self.accu[i]


# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)
class NumArray(object):
    def __init__(self, nums):
        self.nums = nums + [0]
        for i in xrange(len(self.nums)-2, -1, -1):
            self.nums[i] += self.nums[i+1]

    def sumRange(self, i, j):
        return self.nums[i] - self.nums[j+1]
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
