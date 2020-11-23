/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.3MB 100.00%
// hash table
// O(N) O(N)
func isPathCrossing(s string) bool {
  y, x, pos := 0, 0, 0
  set := make(map[int]bool)
  set[pos] = true
  for i := 0; i < len(s); i++ {
    if s[i] == 'N' {
      y--
    } else if s[i] == 'E' {
      x++
    } else if s[i] == 'W' {
      x--
    } else if s[i] == 'S' {
      y++
    }
    pos = y * 10000 + x
    if _, ok := set[pos]; ok {
      return true
    }
    set[pos] = true
  }
  return false
}
