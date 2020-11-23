/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.6MB 100.00%
// sliding window
// O(N) O(1)
func threeConsecutiveOdds(A []int) bool {
  oddCnt := 0
  for i := 0; i < len(A); i++ {
    // pop 
    if i >= 3 && (A[i-3] & 1 == 1) {
      oddCnt--
    } 
    if A[i] & 1 == 1 {
      oddCnt++
    }
    if oddCnt == 3 {
      return true
    }
  }
  return false
}
