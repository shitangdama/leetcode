class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        low, high = 0, len(num) - 1
        
        while low < high:
            mid = low + (high - low) / 2
            if (mid == 0 or num[mid - 1] <= num[mid]) and \
               (mid == len(num) - 1 or num[mid + 1] <= num[mid]):
                return mid
            elif mid > 0 and num[mid - 1] > num[mid]:
                high = mid - 1
            else:
                low = mid + 1
       
        return low

if __name__ == "__main__":
   # print Solution().findPeakElement([1,2,1])
    print Solution().findPeakElement([1,2,3, 1])

class Solution:
    def findPeakInRange(self, num, lhs, rhs):
        mid = (lhs + rhs) // 2
        if (mid == lhs or num[mid] > num[mid - 1]) and \
            (mid == rhs or num[mid] > num[mid + 1]):
            return mid
        if num[mid] < num[mid + 1]:
            return self.findPeakInRange(num, mid + 1, rhs)
        else:
            return self.findPeakInRange(num, lhs, mid)
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        return self.findPeakInRange(num, 0, len(num) - 1)


# debug
s = Solution()
print s.findPeakElement([1, 2, 3, 1])
