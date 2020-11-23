/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

// 4ms 100.00% 6.2MB 100.00%
// BFS
// O(N) O(N)
func averageOfLevels(u *TreeNode) []float64 {
  bfsq := []*TreeNode{u}
  avgs := []float64{}
  for len(bfsq) > 0 {
    n := len(bfsq)
    var sum float64 = 0.0
    for i := 0; i < n; i++ {
      v := bfsq[0]; bfsq = bfsq[1:]
      sum += float64(v.Val)
      if v.Left != nil {
        bfsq = append(bfsq, v.Left)
      }
      if v.Right != nil {
        bfsq = append(bfsq, v.Right)
      }
    }
    avgs = append(avgs, sum / float64(n))
  }
  return avgs
}

func main() {
    fmt.Println("hello world")
}
