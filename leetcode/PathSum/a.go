/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 4ms 96.34% 4.8MB 33.33%
// DFS
// O(N) O(lgN)
func hasPathSum(u *TreeNode, sum int) bool {
	// base
	if u == nil {
		return false
	}
	if u.Left == nil && u.Right == nil && u.Val == sum {
		return true
	}

	// recursion
	l := hasPathSum(u.Left, sum-u.Val)
	r := hasPathSum(u.Right, sum-u.Val)
	return l == true || r == true
}

func main() {
	fmt.Println("hello world")
}
