/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 20ms 83.81% 6MB 100.00%
// math
// O(N) O(1)
func pivotIndex(A []int) int {
	sum := 0
	for _, val := range A {
		sum += val
	}
	leftSum := 0
	for i, val := range A {
		if sum-leftSum-val == leftSum {
			return i
		}
		leftSum += val
	}
	return -1
}

func main() {
	fmt.Println("hello world")
}
