/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 0ms 100.00% 2.2MB 33.33%
func invertTree(u *TreeNode) *TreeNode {
	// base
	if u == nil {
		return nil
	}

	// recursion
	u.Left, u.Right = invertTree(u.Right), invertTree(u.Left)
	return u
}

func main() {
	fmt.Println("hello world")
}
