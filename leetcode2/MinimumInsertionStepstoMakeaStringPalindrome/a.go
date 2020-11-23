/* Copyright (C) 2020 by iamslash */

package main

// i       j
// m b a d m
//     i j
// m b a d m
//   i j
// m b a d m

// 24ms 36.36% 6.6MB 62.50%
// dynamic programming
// O(N) O(lgN)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func dfs(C [][]int, s string, i, j int) int {
	// base
	if i >= j {
		return 0
	}
	// memo
	if C[i][j] >= 0 {
		return C[i][j]
	}
	C[i][j] = 0
	// recursion
	if s[i] == s[j] {
		C[i][j] = dfs(C, s, i+1, j-1)
	} else {
		C[i][j] = 1 + min(dfs(C, s, i+1, j), dfs(C, s, i, j-1))
	}
	return C[i][j]
}
func minInsertions(s string) int {
	C := make([][]int, len(s))
	for i := 0; i < len(s); i++ {
		C[i] = make([]int, len(s))
		for j := 0; j < len(s); j++ {
			C[i][j] = -1
		}
	}
	return dfs(C, s, 0, len(s)-1)
}
