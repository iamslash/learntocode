/* Copyright (C) 2020 by iamslash */

package main

// 12ms 33.33% 6MB 100.00%
// DFS
// O(N) O(lgN)
func dfs(nodes *[]int, u *TreeNode) {
	// base
	if u == nil {
		return
	}
	// recursion
	if u.Left != nil && u.Right != nil {
		dfs(nodes, u.Left)
		dfs(nodes, u.Right)
		return
	}
	if u.Left != nil {
		*nodes = append(*nodes, u.Left.Val)
		dfs(nodes, u.Left)
	}
	if u.Right != nil {
		*nodes = append(*nodes, u.Right.Val)
		dfs(nodes, u.Right)
	}
}
func getLonelyNodes(u *TreeNode) []int {
	nodes := make([]int, 0)
	dfs(&nodes, u)
	return nodes
}
