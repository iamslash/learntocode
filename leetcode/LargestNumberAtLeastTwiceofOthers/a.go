/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"math"
)

// 0ms 100.00% 2.2MB 66.67%
// max 2 numbers
// O(N) O(1)
func dominantIndex(A []int) int {
	max1stVal, max2ndVal := math.MinInt32, math.MinInt32
	max1stIdx := -1
	for i, num := range A {
		if num > max1stVal {
			max2ndVal, max1stVal = max1stVal, num
			max1stIdx = i
		} else if num > max2ndVal {
			max2ndVal = num
		}
	}
	if max1stVal >= max2ndVal+max2ndVal {
		return max1stIdx
	}
	return -1
}

func main() {
	fmt.Println(dominantIndex([]int{0, 0, 0, 1}))
}
