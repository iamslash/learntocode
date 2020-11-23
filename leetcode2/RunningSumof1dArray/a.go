/* Copyright (C) 2020 by iamslash */

package main

// 4ms 65.15% 2.7MB 100.00%
// partial sum
// O(N) O(1)
func runningSum(A []int) []int {
	for i := 1; i < len(A); i++ {
		A[i] += A[i-1]
	}
	return A
}
