class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 要不初始话成最小值，要不初始化第一个值
        result = nums[0]
        dp = [0] * len(nums)
        for i in range(len(nums)):
            # dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            if dp[i-1] and dp[i-1] > 0:
                dp[i] = dp[i-1] + nums[i]
            else:
                dp[i] = nums[i]
            result = max(result,dp[i])
        return result
            
s = Solution()
a = s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
print(a)