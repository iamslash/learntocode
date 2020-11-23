/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 0ms 100.00%
// DFS
// O(N) O(N)
func dfs(u *TreeNode, seq *[]int) {
	if u.Left == nil && u.Right == nil {
		*seq = append(*seq, u.Val)
		return
	}
	if u.Left != nil {
		dfs(u.Left, seq)
	}
	if u.Right != nil {
		dfs(u.Right, seq)
	}
}

func leafSimilar(u *TreeNode, v *TreeNode) bool {
	a, b := []int{}, []int{}
	dfs(u, &a)
	dfs(v, &b)
	if len(a) != len(b) {
		return false
	}
	// fmt.Println(a)
	// fmt.Println(b)
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println("hello world")
}
