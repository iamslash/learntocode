/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//    1
//  /   \
// 2     3
//     /   \
//    4     5
//            \
//             6

// 0ms 100.00% 6.1MB 100.00%
// DFS
// O(N) O(lgN)
func dfs(r *[][]int, u *TreeNode, lv int) {
	// base
	if len(*r) <= lv {
		*r = append(*r, []int{})
	}
	(*r)[lv] = append((*r)[lv], u.Val)

	// recursion
	if u.Left != nil {
		dfs(r, u.Left, lv+1)
	}
	if u.Right != nil {
		dfs(r, u.Right, lv+1)
	}
}

func levelOrderBottom(u *TreeNode) [][]int {

	r := make([][]int, 0)

	if u == nil {
		return r
	}

	dfs(&r, u, 0)
	// reverse
	for i := 0; i < len(r)/2; i++ {
		r[i], r[len(r)-i-1] = r[len(r)-i-1], r[i]
	}
	return r
}

func main() {
	fmt.Println("hello world")
}
