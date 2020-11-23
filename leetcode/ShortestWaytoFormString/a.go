/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 41.18%
// two pointers
// O(ST) O(1)
func shortestWay(s string, t string) int {
  i, j, ans := 0, 0, 0
  for j < len(t) && ans <= j {
    if i < len(s) {
      if s[i] == t[j] {
        i++
        j++
      } else {
        i++
      }
    } else {
      i = 0
      ans++
    }
  }
  ans++
  if ans >= j {
    return -1
  }  
  return ans
}
