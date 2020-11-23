/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 36ms 59.57%
// O(N) O(1)
func canConvertString(s string, t string, k int) bool {
  if len(s) != len(t) {
    return false
  }
  n := len(s)
  cnts := make([]int, 26)
  for i := 0; i < n; i++ {
    diff := (int(t[i]) - int(s[i]) + 26) % 26
    if diff > 0 && cnts[diff] * 26 + diff > k {
      return false
    }
    cnts[diff]++
  }
  return true
}
