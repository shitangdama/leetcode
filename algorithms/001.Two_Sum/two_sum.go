package problem0001

func twoSum(nums []int, target int) []int {
    index := make(map[int]int, len(nums))
    result := []int{-1,-1}
    for i, v := range nums {
        if j, ok := index[target-v]; ok {
            return []int{i, j}
        }
        index[v] = i
    }
    return result
}