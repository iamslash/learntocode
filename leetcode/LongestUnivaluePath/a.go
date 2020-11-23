/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 68ms 100.00% 6.8MB 100.00%
// DFS
// O(N) O(lgN)
var maxPath int = 0

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func dfs(u *TreeNode) int {
	leftPathCnt, rightPathCnt := 0, 0
	leftSamePathCnt, rightSamePathCnt := 0, 0
	if u.Left != nil {
		leftPathCnt = dfs(u.Left)
	}
	if u.Right != nil {
		rightPathCnt = dfs(u.Right)
	}
	if u.Left != nil && u.Left.Val == u.Val {
		leftSamePathCnt = leftPathCnt + 1
	}
	if u.Right != nil && u.Right.Val == u.Val {
		rightSamePathCnt = rightPathCnt + 1
	}
	maxPath = max(maxPath, leftSamePathCnt+rightSamePathCnt)
	return max(leftSamePathCnt, rightSamePathCnt)
}
func longestUnivaluePath(u *TreeNode) int {
	if u == nil {
		return 0
	}
	maxPath = 0
	dfs(u)
	return maxPath
}

func main() {
	fmt.Println("hello world")
}
