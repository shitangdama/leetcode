# Time:  O(logn)
# Space: O(1)

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        low, high = 0, len(A) - 1
        
        while low <= high:
            mid = low + (high - low) / 2
            if A[mid] == target:
                return mid
            elif A[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return low

if __name__ == "__main__":
    print Solution().searchInsert([1, 3, 5, 6], 5)
    print Solution().searchInsert([1, 3, 5, 6], 2)
    print Solution().searchInsert([1, 3, 5, 6], 7)
    print Solution().searchInsert([1, 3, 5, 6], 0)
