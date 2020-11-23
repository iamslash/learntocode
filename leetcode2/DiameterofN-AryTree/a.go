/* Copyright (C) 2020 by iamslash */

package main

// Why Wrong Answer
//   test is ok but submitting [3,null,1,null,5] is wrong.
// DFS
// O(N) O(N)
var ans int

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func dfs(u *Node) int {
	// base
	if u == nil {
		return 0
	}
	// recursion
	cost_1st, cost_2nd := 0, 0
	for _, v := range u.Children {
		cost := dfs(v)
		if cost > cost_1st {
			cost_2nd = cost_1st
			cost_1st = cost
		} else if cost > cost_2nd {
			cost_2nd = cost
		}
	}
	ans = max(ans, cost_1st+cost_2nd)
	return cost_1st + 1
}
func diameter(u *Node) int {
	dfs(u)
	return ans
}
