# Time:  O(n)
# Space: O(1)

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        m = 0
        for i in range(len(nums)):
            if i > m:
                return False

            m = max(m, i+nums[i])

        return True

if __name__ == "__main__":
    print(Solution().canJump([2,3,1,1,4]))
    print(Solution().canJump([3,2,1,0,4]))
