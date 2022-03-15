/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// 13ms 67.66% 7.6MB 68.85%
// lca
// O(N) O(lgN)
func lowestCommonAncestor(u, p, q *TreeNode) *TreeNode {
    // base
    if u == nil || u == p || u == q {
        return u
    }
    // recursion
    l := lowestCommonAncestor(u.Left, p, q)
    r := lowestCommonAncestor(u.Right, p, q)
    if l != nil && r != nil {
        return u;
    }
    if l != nil {
        return l
    }
    return r
}

func main() {
    fmt.Println("hello world")
}
