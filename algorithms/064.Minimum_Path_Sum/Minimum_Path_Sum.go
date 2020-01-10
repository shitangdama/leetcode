package problem0064

import "fmt"

func minPathSum(grid [][]int) int {

	sum := make([][]int, len(grid))
	for i := range sum {
		sum[i] = make([]int, len(grid[0]))
	}
	fmt.Println(sum[0])
	sum[0][0] = grid[0][0]

	for i := 1; i < len(grid[0]); i++ {
		sum[0][i] = sum[0][i-1] + grid[0][i]
	}

	for j := 1; j < len(grid); j++ {
		sum[j][0] = sum[j-1][0] + grid[j][0]
	}

	for i := 1; i < len(grid[0]); i++ {
		for j := 1; j < len(grid); j++ {
			sum[j][i] = grid[j][i]
			if sum[j-1][i] > sum[j][i-1] {
				sum[j][i] += sum[j][i-1]
			} else {
				sum[j][i] += sum[j-1][i]
			}
		}
	}
	return sum[len(grid)-1][len(grid[0])-1]
}
