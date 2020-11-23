/* Copyright (C) 2019 by iamslash */
package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 4ms 99.68% 6.1MB 50.00%
func Max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func Abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func Diff(a int, b int) int {
	return Abs(a - b)
}

func solve(u *TreeNode) (bool, int) {
	// base
	if u == nil {
		return true, 0
	}
	// recursion
	lb, ld := solve(u.Left)
	rb, rd := solve(u.Right)
	if lb == true && rb == true && Diff(ld, rd) < 2 {
		return true, Max(ld, rd) + 1
	}
	return false, 0
}

func isBalanced(root *TreeNode) bool {
	b, _ := solve(root)
	return b
}

func main() {
	fmt.Println("hello world")
}
