/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 3.1MB 100.00%
// linear traversal
// O(N) O(1)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func minOperations(logs []string) int {
  ans := 0
  for _, path := range logs {
    if path == "../" {
      ans = max(0, ans-1)
    } else if path != "./"{
      ans++
    } 
  }
  return ans
}
