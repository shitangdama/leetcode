package problem0053

func maxSubArray(nums []int) int {
	l := len(nums)
	dp := make([]int, l)
	result := nums[0]
	for i, _ := range nums {
		if i != 0 && dp[i-1] > 0 {
			dp[i] = dp[i-1] + nums[i]
		} else {
			dp[i] = nums[i]
		}

		if result < dp[i] {
			result = dp[i]
		}

	}

	return result
}
