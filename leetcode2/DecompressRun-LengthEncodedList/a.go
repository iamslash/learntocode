/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 92.78% 5.9MB 100.00%
// brute force
// O(N) O(N)
func decompressRLElist(A []int) []int {
  ans := []int{}
  for i := 0; i < len(A); i += 2 {
    cnt := A[i]
    for j := 0; j < cnt; j++ {
      ans = append(ans, A[i+1])
    }
  }
  return ans
}
