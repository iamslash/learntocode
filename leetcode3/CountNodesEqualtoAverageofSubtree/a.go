/* Copyright (C) 2023 by iamslash */

package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// 0ms 100.00% 4.9MB 5.71%
// dfs
// O(N) O(lgN)
func dfs(u *TreeNode, best *int) []int {
    // base
    if (u == nil) {
        return []int{0, 0}
    }
    // recursion
    lrst := dfs(u.Left, best)
    rrst := dfs(u.Right, best)
    sum  := lrst[0] + rrst[0] + u.Val
    cnt  := lrst[1] + rrst[1] + 1
    if (sum / cnt) == u.Val {
        (*best) += 1
    }        
    return []int{sum, cnt}
}
func averageOfSubtree(root *TreeNode) int {
    best := 0
    dfs(root, &best)
    return best
}

func main() {
    fmt.Println("hello world")
}
