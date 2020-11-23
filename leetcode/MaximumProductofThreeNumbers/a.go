/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

// max1
// max2
// max3
// ...
// min2
// min1
// answer = max(max1*max2*max3, max1*min1*min2)

// 32ms 100.00% 6.3MB 100.00%
// dynamic programming
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maximumProduct(A []int) int {
	max1, max2, max3 := math.MinInt32, math.MinInt32, math.MinInt32
	min2, min1 := math.MaxInt32, math.MaxInt32
	for _, num := range A {
		if num > max1 {
			max3, max2, max1 = max2, max1, num
		} else if num > max2 {
			max3, max2 = max2, num
		} else if num > max3 {
			max3 = num
		}
		if num < min1 {
			min2, min1 = min1, num
		} else if num < min2 {
			min2 = num
		}
	}
	return max(max1*max2*max3, max1*min2*min1)
}

func main() {
	fmt.Println("hello world")
}
