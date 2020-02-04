package problem0045

func jump(nums []int) int {
	n := len(nums)
	step := 0
	next_max := 0
	cur_max := 0

	if nums == nil || n == 1 {
		return 0
	}

	for i := 0; i < n; i++ {
		if next_max < i+nums[i] {
			next_max = i + nums[i]
		}

		if next_max >= n-1 {
			return step + 1
		}

		if i == cur_max {
			step = step + 1
			cur_max = next_max
		}
	}
	return 0
}
