class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        return min(nums)
class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        # write your code here
        min = num[0]
        start, end = 0, len(num) - 1
        while start<end:
            mid = (start+end)/2
            if num[mid]>num[end]:
                start = mid+1
            elif num[mid]<num[end]:
                end = mid
            else:
                end = end - 1
        return num[start]
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num)
           
        while low < high - 1 and num[low] >= num[high - 1]:
            mid = low + (high - low) / 2
                
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                if mid == high - 1:
                    return num[mid]
                else:
                    high = mid + 1
            else:
                low += 1

        return num[low]

class Solution2:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num) - 1
           
        while low < high and num[low] >= num[high]:
            mid = low + (high - low) / 2
            
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                high = mid
            else:
                low += 1

        return num[low]

if __name__ == "__main__":
    print Solution().findMin([3, 1, 1, 2, 2, 3])
    print Solution2().findMin([2, 2, 2, 3, 3, 1])
