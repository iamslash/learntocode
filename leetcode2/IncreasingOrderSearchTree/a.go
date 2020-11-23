/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//        5
//       / \
//     3    6
//    / \    \
//   2   4    8
//  /        / \
// 1        7   9

// 0ms 100.00% 2.5MB 100.00%
// inorder traversal
// O(N) O(lgN)
var root *TreeNode
var tail *TreeNode

func dfs(u *TreeNode) {
	// base
	if u == nil {
		return
	}
	// recursion
	dfs(u.Left)
	if root == nil {
		root = u
		tail = u
	} else if tail != nil {
		tail.Right = u
		tail = u
		u.Left = nil
	}
	dfs(u.Right)
}
func increasingBST(u *TreeNode) *TreeNode {
	root = nil
	tail = nil
	dfs(u)
	return root
}

func main() {
	fmt.Println("hello world")
}
