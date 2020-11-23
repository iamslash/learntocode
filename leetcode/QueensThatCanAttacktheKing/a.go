/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.7MB 100.00%
// brute force
// O(1) O(1)
func queensAttacktheKing(Q [][]int, K []int) [][]int {
  B := [8][8]bool{}
  for _, q := range Q {
    B[q[0]][q[1]] = true
  }
  dirs := [][]int{{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}}
  r := [][]int{}
  for _, dir := range dirs {
    nx := K[0] + dir[0]
    ny := K[1] + dir[1]
    for nx >= 0 && nx < 8 && ny >= 0 && ny < 8 {
      if B[nx][ny] {
        r = append(r, []int{nx, ny})
        break
      }
      nx += dir[0]
      ny += dir[1]
    }
  }
  return r
}

func main() {
  fmt.Println("hello world")
}
