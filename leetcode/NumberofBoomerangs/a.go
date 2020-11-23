/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 204ms 33.33% 7.5MB 100.00%
// hash map
// combination
// O(N^2) O(N)
func getDist(a []int, b []int) int {
  dx := a[0] - b[0]
  dy := a[1] - b[1]
  return dx * dx + dy * dy
}
func numberOfBoomerangs(P [][]int) int {
  r := 0
  for i := 0; i < len(P); i++ {
    dist2CntMap := make(map[int]int)
    for j := 0; j < len(P); j++ {
      if i == j {
        continue
      }
      dist := getDist(P[i], P[j])
      dist2CntMap[dist] += 1
    }
    for _, v := range dist2CntMap {
      r += v * (v - 1)
    }
  }
  return r
}

func main() {
  fmt.Println("hello world")
}
