/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"strconv"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//      1
//    /   \
//   2     3
//  /
// 4

// // 12ms 67,35% 7.1MB 100.00%
// // DFS
// // O(N) O(N)
// func tree2str(u *TreeNode) string {
// 	// base
// 	if u == nil {
// 		return ""
// 	}
// 	sb := strings.Builder{}
// 	sb.WriteString(fmt.Sprintf("%d", u.Val))
// 	if (u.Left == nil && u.Right != nil) ||
// 		u.Left != nil {
// 		sb.WriteString("(")
// 		sb.WriteString(tree2str(u.Left))
// 		sb.WriteString(")")
// 	}
// 	if u.Right != nil {
// 		sb.WriteString("(")
// 		sb.WriteString(tree2str(u.Right))
// 		sb.WriteString(")")
// 	}
// 	return sb.String()
// }

// 8ms 89.80% 6.7MB 100.00%
// DFS
// O(N) O(N)
func tree2str(t *TreeNode) string {
	// base
	if t == nil {
		return ""
	}
	// recursion
	s := strconv.Itoa(t.Val)
	if t.Left != nil || t.Right != nil {
		s += "(" + tree2str(t.Left) + ")"
	}
	if t.Right != nil {
		s += "(" + tree2str(t.Right) + ")"
	}
	return s
}

func main() {
	fmt.Println("hello world")
}
