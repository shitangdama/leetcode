# Time:  O(n)
# Space: O(1)

class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        n = len(nums)
        if not n or n == 1:
            return 0

# cur_max表示跳i步能达到最远的坐标
# next_max表示在cur_max之前的位置跳一步能达到下一个最远的位置
        next_max = cur_max = 0

        step = 0
        for i in range(n):
            next_max = max(nums[i]+i, next_max)
            if next_max>=n-1:
                return step+1
            if i == cur_max:
                step += 1
                cur_max = next_max

if __name__ == "__main__":
    print(Solution().jump([2,3,1,1,4]))
    print(Solution().jump([3,2,1,0,4]))
