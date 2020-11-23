/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 0ms 100.00% 2.1MB 50.00%
// DFS
// O(N) O(N)
func isSameTree(p *TreeNode, q *TreeNode) bool {
	// base
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) &&
		isSameTree(p.Right, q.Right)
}

func main() {
	fmt.Println("hello world")
}
