
/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "sort"
)

// G: 1 2 3
// S: 1 1

//        i
// G: 6 7
// S: 1 6 7
//        j

// 32ms 96.83% 6MB 100.00%
// greedy
// O(NlgN) O(1)
func findContentChildren(G []int, S []int) int {
  sort.Ints(G)
  sort.Ints(S)
  i, j := 0, 0
  for i, j = 0, 0; i < len(G) && j < len(S); j++ {
    if G[i] <= S[j] {
      i++
    }
  }
  return i
}

func main() {
  fmt.Println("hello world")
}
