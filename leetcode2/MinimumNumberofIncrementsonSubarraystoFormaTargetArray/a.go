/* Copyright (C) 2020 by iamslash */

package main

//              i
//   T: 3 1 5 4 2
//   p: 3 1 5 4 2
// ans: 7

// // 112ms 100.00% 8.1MB 59.09%
// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }
// func minNumberOperations(T []int) int {
// 	prv, ans := 0, 0
// 	for i := 0; i < len(T); i++ {
// 		ans += max(0, T[i]-prv)
// 		prv = T[i]
// 	}
// 	return ans
// }

// 120ms 87.50% 7.5MB 00.00%
// O(N) O(1)
func minNumberOperations(A []int) int {
	ans := A[0]
	for i := 1; i < len(A); i++ {
		if A[i] > A[i-1] {
			ans += A[i] - A[i-1]
		}
	}
	return ans
}
