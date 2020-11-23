/* Copyright (C) 2020 by iamslash */

package main

//     A: 1 2
// minPs: 1 1
//

// 0ms 100.00% 2MB 69.57%
// partial sum
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func minStartValue(A []int) int {
	minPs := A[0]
	for i := 1; i < len(A); i++ {
		A[i] += A[i-1]
		minPs = min(minPs, A[i])
	}
	return max(1, 1-minPs)
}
