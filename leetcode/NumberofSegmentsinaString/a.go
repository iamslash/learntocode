/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
)

// "     b c"

// 0ms 100.00% 1.9MB 100.00%
// brute force
// O(N) O(1)
func countSegments(s string) int {
  i, n, r := 0, len(s), 0
  // skip white spaces
  for i < n && s[i] == ' ' {
    i++
  }
  for i < n {
    r++
    for i < n && s[i] != ' ' {
      i++
    }
    for i < n && s[i] == ' ' {
      i++
    }
  }
  return r
}

func main() {
  fmt.Println(countSegments("Hello, my name is John"))
  fmt.Println(countSegments(""))
  fmt.Println(countSegments("   "))
  fmt.Println(countSegments(" a d d  "))
}
