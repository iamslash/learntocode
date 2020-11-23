/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 32ms 41.67% 7.1MB 100.00%
// DFS
// O(N) O(N)
func buildSet(u *TreeNode, valueSet map[int]bool) {
	// base
	if u == nil {
		return
	}
	valueSet[u.Val] = true

	// recursion
	buildSet(u.Left, valueSet)
	buildSet(u.Right, valueSet)
}

func traverse(u *TreeNode, valueSet map[int]bool, tgt int) bool {
	// base
	if u == nil {
		return false
	}
	if _, ok := valueSet[tgt-u.Val]; ok {
		return true
	}

	// recursion
	return traverse(u.Left, valueSet, tgt) ||
		traverse(u.Right, valueSet, tgt)
}

func twoSumBSTs(u *TreeNode, v *TreeNode, tgt int) bool {
	valueSet := make(map[int]bool)
	buildSet(u, valueSet)
	return traverse(v, valueSet, tgt)
}

func main() {
	u := &TreeNode{0,
		&TreeNode{-10, nil, nil},
		&TreeNode{10, nil, nil}}
	v := &TreeNode{5,
		&TreeNode{1,
			&TreeNode{0, nil, nil},
			&TreeNode{2, nil, nil}},
		&TreeNode{7, nil, nil}}
	tgt := 17
	fmt.Println(twoSumBSTs(u, v, tgt))
}
