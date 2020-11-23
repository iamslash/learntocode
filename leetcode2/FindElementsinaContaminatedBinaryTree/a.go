/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 32ms 90.00% 7.7MB 100.00%
// hash map
// Find: O(N) O(N)
type FindElements struct {
	valMap map[int]bool
}

func dfs(u *TreeNode, val int, valMap map[int]bool) {
	// base
	if u == nil {
		return
	}
	u.Val = val
	valMap[u.Val] = true
	//fmt.Println(valMap)
	dfs(u.Left, val*2+1, valMap)
	dfs(u.Right, val*2+2, valMap)
}
func Constructor(u *TreeNode) FindElements {
	valMap := make(map[int]bool)
	dfs(u, 0, valMap)
	return FindElements{
		valMap: valMap,
	}
}
func (fe *FindElements) Find(a int) bool {
	return fe.valMap[a]
}

func main() {
	fmt.Println("hello world")
}
