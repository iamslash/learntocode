/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// 0ms 100.00% 2.4MB 70.66%
// BFS
// O(N) O(N)
type Pair struct {
    order int
    node *TreeNode
}
func verticalOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    valsMap := make(map[int][]int)
    q := []Pair{ Pair{order: 0, node: root } }
    minOrder, maxOrder := 0, 0
    for len(q) > 0 {
        p := q[0]
        q = q[1:]
        vals := valsMap[p.order]
        if vals == nil {
            vals = make([]int, 0)
        }
        vals = append(vals, p.node.Val)
        valsMap[p.order] = vals
        if minOrder > p.order {
            minOrder = p.order
        }
        if maxOrder < p.order {
            maxOrder = p.order
        }
        if p.node.Left != nil {
            q = append(q, Pair{ order: p.order - 1, node: p.node.Left })
        }
        if p.node.Right != nil {
            q = append(q, Pair{ order: p.order + 1, node: p.node.Right })
        }
    }
    ans := make([][]int, 0, maxOrder - minOrder + 1)
    for i := minOrder; i <= maxOrder; i++ {
        ans = append(ans, valsMap[i])
    }
    return ans
}

func main() {
    fmt.Println("hello world")
}
