/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Wrong Answer: [1,null,5,3]
// console work but sumbit does not
// inorder
// O(N) O(lgN)
var (
	prvVal int = -1
	minDif int = math.MaxInt64
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func inorder(u *TreeNode) {
	// base
	if u == nil {
		return
	}
	// recursion
	inorder(u.Left)
	if prvVal >= 0 {
		curDif := abs(u.Val) - abs(prvVal)
		minDif = min(minDif, curDif)
	}
	prvVal = u.Val
	inorder(u.Right)
}
func getMinimumDifference(u *TreeNode) int {
	inorder(u)
	return minDif
}

func main() {
	fmt.Println("hello world")
}
