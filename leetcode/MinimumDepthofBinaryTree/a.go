/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 4ms 97.12% 5.1MB 100.00%
// BFS
// O(N) O(lgN)
func minDepth(root *TreeNode) int {
	q := []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
	r := 0
	for len(q) > 0 {
		n := len(q)
		r++
		for i := 0; i < n; i++ {
			u := q[0]
			q = q[1:]
			if u.Left == nil && u.Right == nil {
				return r
			}
			if u.Left != nil {
				q = append(q, u.Left)
			}
			if u.Right != nil {
				q = append(q, u.Right)
			}
		}
	}
	return r
}

func main() {
	fmt.Println("hello world")
}
