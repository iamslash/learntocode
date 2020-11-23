/* Copyright (C) 2020 by iamslash */

package main

// S: 1 2 3 4 5 6
//
//
//     0 1 2
//   0 0 0 0
// 1 1 0 1 1
// 2 2 0 2 2
// 3 3 0 3 4
// 4 4 0 4 6
// 5 5 0 5 8

//     0 1 2
//   0 0 0 0
// 2 1 0 2 2
// 3 2 0 3 3
// 4 3 0 4 6
// 5 4 0 5 8
// 6 5 0 6 10

// 4ms 100.00% 6.2MB 100.00%
// dynamic programming
// O(N^2) O(N^2)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSize(A []int) int {
	n, m := len(A), (len(A)+1)/3
	C := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		C[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if i == 1 {
				C[i][j] = A[0]
				continue
			}
			C[i][j] = max(C[i-1][j], C[i-2][j-1]+A[i-1])
		}
	}
	return C[n][m]
}
func maxSizeSlices(S []int) int {
	return max(maxSize(S[:len(S)-1]), maxSize(S[1:]))
}
