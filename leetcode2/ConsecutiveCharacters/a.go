/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//  i
// leetcode
//    j

// 4ms 25.20% 2.4MB 31.43%
// linear traversal
// O(N) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func maxPower(s string) int {
  ans, n := 0, len(s)
  for i, j := 0, 0; i < n; i = j {
    for j < n && s[i] == s[j] {
      j++  
      ans = max(ans, j - i)
    }
  }
  return ans
}
