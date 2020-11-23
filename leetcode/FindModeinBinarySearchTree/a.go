/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Wrong Answer: [2147483647]
// work in console but does not work in submit
// inorder
// O(N) O(lgN)
var (
	curMod int = math.MinInt64
	curCnt int = 0
	maxCnt int = 0
	modCnt int = 0
)

func handle(val int, modes []int) {
	if val != curMod {
		curMod = val
		curCnt = 0
	}
	curCnt++
	if curCnt > maxCnt {
		maxCnt = curCnt
		modCnt = 1
	} else if curCnt == maxCnt {
		if modes != nil {
			modes[modCnt] = curMod
		}
		modCnt++
	}
}
func inorder(u *TreeNode, modes []int) {
	// base
	if u == nil {
		return
	}
	// recursion
	inorder(u.Left, modes)
	handle(u.Val, modes)
	inorder(u.Right, modes)
}
func findMode(u *TreeNode) []int {
	// find max mod
	inorder(u, nil)
	modes := make([]int, modCnt)
	curCnt = 0
	modCnt = 0
	// gather modes
	inorder(u, modes)
	return modes
}

func main() {
	fmt.Println("hello world")
}
