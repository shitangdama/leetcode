class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, nums):
        if len(nums) == 0:
            return 0
            
        start, end = 0, len(nums) - 1
        target = nums[-1]
        while start + 1 < end:
            mid = (start + end) / 2
            if nums[mid] <= target:
                end = mid
            else:
                start = mid
        return min(nums[start], nums[end])
    class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num)
           
        while low < high - 1 and  num[low] >= num[high - 1]:
            mid = low + (high - low) / 2
                
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                if mid == high - 1:
                    return num[mid]
                else:
                    high = mid + 1
            else:
                return num[mid]

        return num[low]

class Solution2:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num) - 1
           
        while low < high and num[low] >= num[high]:
            mid = low + (high - low) / 2
            
            if num[mid] >= num[low]:
                low = mid + 1
            else:
                high = mid

        return num[low]

if __name__ == "__main__":
    print Solution().findMin([1])
    print Solution().findMin([1, 2])
    print Solution().findMin([2, 1])
    print Solution().findMin([3, 1, 2])
    print Solution().findMin([2, 3, 1])

