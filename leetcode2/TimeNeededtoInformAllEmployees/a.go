/* Copyright (C) 2020 by iamslash */

package main

// 204ms 93.62% 11.9MB 65.85%
// DFS
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func dfs(G [][]int, time []int, u int) int {
	// recursion
	ans := 0
	for _, v := range G[u] {
		ans = max(ans, dfs(G, time, v))
	}
	return ans + time[u]
}
func numOfMinutes(n int, head int, manager []int, time []int) int {
	G := make([][]int, n)
	for v := 0; v < len(manager); v++ {
		u := manager[v]
		if v != head {
			G[u] = append(G[u], v)
		}
	}
	return dfs(G, time, head)
}
