class Solution:
    # @param num, a list of integer
    # @return an integer
    def rob(self, num):
        if len(nums) == 0:
            return 0

        if len(nums) == 1:
            return nums[0]

        dp = [0]*len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[1], nums[0])

        for i in range(2, len(nums)):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        return dp[-1]

if __name__ == '__main__':
        printSolution().rob([8,4,8,5,9,6,5,4,4,10])
