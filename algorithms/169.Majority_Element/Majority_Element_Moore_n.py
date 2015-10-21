class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        cnt = 0
        for i in num:
            if cnt == 0:
                ret = i
            cnt += 1 if ret == i else -1
        return ret
class Solution:

    def majorityNumber(self, nums):
        candidate = None
        count = 0
        for num in nums:
            if count == 0:
                candidate = num
                count += 1
            elif candidate == num:
                count += 1
            else:
                count -= 1
        return candidate
# debug
s = Solution()
print s.majorityElement([1, 2, 2, 2, 3])

