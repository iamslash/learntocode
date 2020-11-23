/* Copyright (C) 2020 by iamslash */

package main

// (1, 0)

// 1 0 0
// 1 1 0
// 1 0 1

// 112ms 92.86% 7.1MB 45.45%
// floyd-warshall algorithm
// O(N^3) O(N^2)
func checkIfPrerequisite(n int, P [][]int, Q [][]int) []bool {
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		G[i][i] = 1
	}
	for i := 0; i < len(P); i++ {
		G[P[i][0]][P[i][1]] = 1
	}
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if G[i][k] == 1 && G[k][j] == 1 {
					G[i][j] = 1
				}
			}
		}
	}
	ans := make([]bool, len(Q))
	for i := 0; i < len(Q); i++ {
		if G[Q[i][0]][Q[i][1]] == 1 {
			ans[i] = true
		}
	}
	return ans
}
