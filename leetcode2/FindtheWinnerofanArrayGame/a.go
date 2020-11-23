/* Copyright (C) 2020 by iamslash */

package main

// k: 3
//    i
// A: 3 2 1
//

// // 152ms 39.25% 8.7MB 45.79%
// // linear traversal
// // O(N) O(1)
// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }
// func getWinner(A []int, k int) int {
// 	n, maxA := len(A), 0
// 	for i := 0; i < n; i++ {
// 		cnt := 0
// 		if i > 0 && A[i-1] < A[i] {
// 			cnt++
// 		}
// 		for j := i + 1; j < n && A[i] > A[j]; j++ {
// 			cnt++
// 		}
// 		if cnt >= k {
// 			return A[i]
// 		}
// 		maxA = max(maxA, A[i])
// 	}
// 	return maxA
// }

// 120ms 46.73% 9.2MB 35.51%
// linear traversal
// O(N) O(1)
func getWinner(A []int, k int) int {
	n, cur, win := len(A), A[0], 0
	for i := 1; i < n; i++ {
		if cur < A[i] {
			cur = A[i]
			win = 0
		}
		win++
		if win == k {
			break
		}
	}
	return cur
}
