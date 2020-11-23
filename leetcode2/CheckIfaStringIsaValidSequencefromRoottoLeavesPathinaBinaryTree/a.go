/* Copyright (C) 2020 by iamslash */

package main

//       8
//      /
//     3
//    / \
//   2   1
//  / \
// 5   4

// 44ms 6.67% 6.7MB 100.00%
// DFS
// O(N) O(lgN)
func dfs(u *TreeNode, A []int, i int) bool {
	// base
	if u == nil || i >= len(A) || u.Val != A[i] {
		return false
	}
	if u.Left == nil && u.Right == nil && i == len(A)-1 {
		return true
	}
	// recursion
	return dfs(u.Left, A, i+1) || dfs(u.Right, A, i+1)
}
func isValidSequence(u *TreeNode, A []int) bool {
	return dfs(u, A, 0)
}
