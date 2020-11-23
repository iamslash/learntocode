/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

// 4ms 94.44% 3.9MB 100.00%
// brute force
// O(MN) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maxCount(m int, n int, ops [][]int) int {
	minI, minJ := m, n
	for _, op := range ops {
		minI = min(minI, op[0])
		minJ = min(minJ, op[1])
	}
	return minI * minJ
}

func main() {
	fmt.Println("hello world")
}
