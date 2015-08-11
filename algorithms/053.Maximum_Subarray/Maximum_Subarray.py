# Time:  O(n)
# Space: O(1)

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        global_max, local_max = float("-inf"), 0
        for x in A:
            local_max = max(0, local_max + x)
            global_max = max(global_max, local_max)
        return global_max

if __name__ == "__main__":
    print Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])                                    
