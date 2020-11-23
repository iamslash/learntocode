/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0 1 0 0
// 1 1 1 0
// 0 1 0 0
// 1 1 0 0

// 84ms 10.96% 6.6MB 100.00%
// math
// O(HW) O(1)
func islandPerimeter(G [][]int) int {
  if len(G) == 0 {
    return 0
  }
  cnt := 0
  for y := 0; y < len(G); y++ {
    for x := 0; x < len(G[0]); x++ {
      if G[y][x] == 1 {
        cnt += 4
        if y > 0 && y < len(G) && G[y-1][x] == 1 {
          cnt -= 2
        }
        if x > 0 && x < len(G[0]) && G[y][x-1] == 1 {
          cnt -= 2
        }
      }
    }
  }
  return cnt;
}

func main() {
  fmt.Println("hello world")
}
