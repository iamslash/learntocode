/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 96ms 75.95% 7.8MB 100.00%
// inorder traversal
// O(N) O(lgN)
func rangeSumBST(u *TreeNode, L int, R int) int {
	// base
	if u == nil {
		return 0
	}
	if u.Val >= L && u.Val <= R {
		return u.Val + rangeSumBST(u.Left, L, R) + rangeSumBST(u.Right, L, R)
	} else if u.Val < L {
		return rangeSumBST(u.Right, L, R)
	} else if u.Val > R {
		return rangeSumBST(u.Left, L, R)
	}
	return 0
}

func main() {
	fmt.Println("hello world")
}
