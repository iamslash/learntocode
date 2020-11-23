/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// // 32ms 36.08% 8.6MB 100.00
// // DFS
// // O(N) O(lgN)
// func mergeTrees(u *TreeNode, v *TreeNode) *TreeNode {
// 	// base
// 	if u == nil && v == nil {
// 		return nil
// 	}
// 	r := &TreeNode{}
// 	if u != nil && v != nil {
// 		r.Val = u.Val + v.Val
// 		r.Left = mergeTrees(u.Left, v.Left)
// 		r.Right = mergeTrees(u.Right, v.Right)
// 	} else if u == nil {
// 		r.Val = v.Val
// 		r.Left = mergeTrees(nil, v.Left)
// 		r.Right = mergeTrees(nil, v.Right)
// 	} else if v == nil {
// 		r.Val = u.Val
// 		r.Left = mergeTrees(u.Left, nil)
// 		r.Right = mergeTrees(u.Right, nil)
// 	}
// 	return r
// }

// 28ms 89.18% 8.6MB 100.00%
// DFS
// O(N) O(lgN)
func mergeTrees(u *TreeNode, v *TreeNode) *TreeNode {
	// base
	if u == nil && v == nil {
		return nil
	}
	var w *TreeNode
	if u != nil && v != nil {
		w = &TreeNode{
			Val:   u.Val + v.Val,
			Left:  mergeTrees(u.Left, v.Left),
			Right: mergeTrees(u.Right, v.Right),
		}
	} else if u == nil {
		w = v
	} else if v == nil {
		w = u
	}
	return w
}

func main() {
	fmt.Println("hello world")
}
