package problem046

func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	ans := make([][]int, 0)
	dfs(nums, nil, &ans)

	return ans
}

func dfs(nums []int, prev []int, ans *[][]int) {
	if len(nums) == 0 {
		*ans = append(*ans, append([]int{}, prev...))
		return
	}

	for i := 0; i < len(nums); i++ {
		dfs(append(append([]int{}, nums[0:i]...), nums[i+1:]...),
			append(prev, nums[i]),
			ans)
	}
}
