/* Copyright (C) 2020 by iamslash */

package main

// 184ms 91.07% 16.7MB 96.43%
// indegree
// O(N) O(N)
func findSmallestSetOfVertices(n int, E [][]int) []int {
	indeg := make([]int, n)
	for _, e := range E {
		indeg[e[1]]++
	}
	ans := []int{}
	for i := 0; i < n; i++ {
		if indeg[i] == 0 {
			ans = append(ans, i)
		}
	}
	return ans
}
