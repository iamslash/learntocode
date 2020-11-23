/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// abcdefgabcdefg
// l: 2
// r: 5
// d: -3

// abcabc
// l: 1
// r: 2
// d: -1

// 0ms 100.00% 2.1MB 100.00%
// modulo
// O(N) O(1)
func stringShift(s string, shifts [][]int) string {
  ldir, rdir, n := 0, 0, len(s)
  for _, shift := range shifts {
    if shift[0] == 0 {
      ldir += shift[1]
    } else {
      rdir += shift[1]
    }
  }
  diff := (ldir - rdir)%n
  ss := s + s
  if diff < 0 {
    return ss[n+diff:2*n+diff]
  }
  return ss[diff:diff+n]
}
