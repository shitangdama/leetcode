package problem0015

import "sort"

func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    result := [][]int{}

    for i, _ := range nums{
        j, k := i+1, len(nums)-1

        if i > 0 && nums[i] == nums[i-1] {
            continue
        }

        for j < k {
            if nums[i] + nums[j] + nums[k] > 0 {
                k--
            } else if nums[i] + nums[j] + nums[k] < 0 {
                j++
            } else {
                result = append(result, []int{nums[i], nums[j], nums[k]})
                j++
                k--
                for j < k && nums[j] == nums[j-1] {
                    j++
                }
                for j < k && nums[k] == nums[k+1] {
                    k--
                }
            }
        }
    }

    return result
}