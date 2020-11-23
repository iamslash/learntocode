/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//    2
//  /   \
// 1     3

// Why Wrong Answer??? 2020.02.07
// Input:
// [2,1,3]
// Output:
// [25,26,23]
// Expected:
// [5,6,3]
//
// DFS
// O(N) O(lgN)
var sum int = 0

func dfs(u *TreeNode) {
	// base
	if u == nil {
		return
	}
	dfs(u.Right)
	sum += u.Val
	u.Val = sum
	dfs(u.Left)
}
func convertBST(u *TreeNode) *TreeNode {
	dfs(u)
	return u
}

func main() {
	fmt.Println("hello world")
}
