/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 24ms 84.18% 6.7MB 100.00%
// BST
// O(lgN) O(lgN)
func searchBST(u *TreeNode, val int) *TreeNode {
	// base
	if u.Val == val {
		return u
	}
	if val < u.Val && u.Left != nil {
		return searchBST(u.Left, val)
	}
	if val > u.Val && u.Right != nil {
		return searchBST(u.Right, val)
	}
	return nil
}

func main() {
	fmt.Println("hello world")
}
