/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//        i
// A: 3 6 5 1 8
//
// C: 9 0 14
// T: 9 0 0

// [3 0 0]
// [9 0 0]
// [9 19 14]
// [21 19 20]
// [27 37 29]
// 27

// 36ms 46.51% 6.3MB 100.00%
// dynamic programming
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSumDivThree(A []int) int {
	C, T := make([]int, 3), make([]int, 3)
	for _, a := range A {
		copy(T, C)
		for _, b := range T {
			sum := a + b
			C[sum%3] = max(C[sum%3], sum)
		}
	}
	return C[0]
}

func main() {
	A := []int{3, 6, 5, 1, 8}
	fmt.Println(maxSumDivThree(A))
}
