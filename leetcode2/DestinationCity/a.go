/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// B C
// D B
// C A

// 4ms 91.83% 4.1MB 68.31%
// hash map
// O(N) O(N)
func destCity(P [][]string) string {
  outDeg := make(map[string]int)
  for _, path := range P {
    outDeg[path[0]]++
    outDeg[path[1]] = outDeg[path[1]]
  }
  ans := ""
  for k, v := range outDeg {
    if v == 0 {
      ans = k
      break
    }
  }
  return ans
}
