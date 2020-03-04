package main

import (
	"fmt"
)

func main() {
	array := []int{3, 6, 1, 4, 2, 8}
	fmt.Println(array)
	quickSort(array, 0, len(array)-1)
	fmt.Println(array)
}

func quickSort(sortArray []int, left, right int) {
	if left < right {
		pos := partition(sortArray, left, right)
		partition(sortArray, left, pos-1)
		partition(sortArray, pos+1, right)
	}
}

func partition(sortArray []int, left, right int) int {
	key := sortArray[right]
	i := left - 1

	for j := left; j < right; j++ {
		if sortArray[j] <= key {
			i++
			sortArray[i], sortArray[j] = sortArray[j], sortArray[i]
		}
	}

	sortArray[i+1], sortArray[right] = sortArray[right], sortArray[i+1]

	return i + 1
}
