/* Copyright (C) 2020 by iamslash */

package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 60ms 22.89% 6.8MB 43.37%
// post-order
// O(N) O(lgN)
var ans int

func dfs(u *TreeNode, dist int) []int {
	// base
	if u == nil {
		return make([]int, 11)
	}
	// recursion
	leftList := dfs(u.Left, dist)
	rightList := dfs(u.Right, dist)
	rootList := make([]int, 11)
	//
	if u.Left == nil && u.Right == nil {
		rootList[1] = 1
		return rootList
	}
	//
	for i := 0; i <= 10; i++ {
		for j := 0; j <= 10; j++ {
			if i+j <= dist {
				ans += (leftList[i] * rightList[j])
			}
		}
	}
	//
	for i := 0; i <= 9; i++ {
		rootList[i+1] += leftList[i]
		rootList[i+1] += rightList[i]
	}
	return rootList
}
func countPairs(u *TreeNode, dist int) int {
	ans = 0
	dfs(u, dist)
	return ans
}
