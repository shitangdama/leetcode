package problem0121

func maxProfit(prices []int) int {

	var max int = 0
	var tmp int = 0

	for i := 1; i < len(prices); i++ {
		tmp += prices[i] - prices[i-1]
		if tmp < 0 {
			tmp = 0
		}
		if max < tmp {
			max = tmp
		}
	}

	return max
}
