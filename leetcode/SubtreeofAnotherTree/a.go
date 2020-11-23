/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 20ms 61.03% 6.2MB 100.00%
// DFS
// O(N^2) O(lgN)
func dfs(u *TreeNode, v *TreeNode) bool {
	// base
	if u == nil {
		return v == nil
	}
	if v == nil {
		return false
	}
	return u.Val == v.Val && dfs(u.Left, v.Left) && dfs(u.Right, v.Right)
}
func isSubtree(s *TreeNode, t *TreeNode) bool {
	if s == nil {
		return t == nil
	}
	return dfs(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t)
}

func main() {
	fmt.Println("hello world")
}
