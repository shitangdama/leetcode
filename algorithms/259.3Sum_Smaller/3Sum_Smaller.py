<<<<<<< HEAD
class Solution(object):
    def threeSumSmaller(self, nums, target):
        # sort first and then use three pointers
        n = len(nums)
        if n < 3:
            return 0
        nums.sort()
        count = 0
        for i in range(1, n - 1):
            start = 0
            end = n - 1
            cur = target - nums[i]
            # search for valid tuple in O(n)
            while start < i and end > i:
                if nums[start] + nums[end] < cur:
                    count += end - i
                    start += 1
                else:
                    end -= 1
        return count
        
=======
class Solution(object):
    def threeSumSmaller(self, nums, target):
        # sort first and then use three pointers
        n = len(nums)
        if n < 3:
            return 0
        nums.sort()
        count = 0
        for i in range(1, n - 1):
            start = 0
            end = n - 1
            cur = target - nums[i]
            # search for valid tuple in O(n)
            while start < i and end > i:
                if nums[start] + nums[end] < cur:
                    count += end - i
                    start += 1
                else:
                    end -= 1
        return count
        
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
