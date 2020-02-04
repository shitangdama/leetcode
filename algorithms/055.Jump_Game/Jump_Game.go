package problem0055

func canJump(nums []int) bool {
	m := 0

	for i := 0; i < len(nums); i++ {
		if m < i {
			return false
		}

		if i+nums[i] > m {
			m = i + nums[i]
		}

	}
	return true
}
