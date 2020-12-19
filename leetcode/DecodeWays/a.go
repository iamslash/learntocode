/* Copyright (C) 2020 by iamslash */

package main

import "fmt"
import "strconv"

// 0ms 100.00% 2MB 48.55%
// iterative dynamic programming
// O(N) O(1)
func numDecodings(s string) int {
  if len(s) == 0 || s[0] == '0' {
    return 0
  }
  n1, n2 := 1, 0
  for i := 1; i < len(s); i++ {
    m1, m2 := 0, 0
    if s[i] >= '1' && s[i] <= '9' {
      m1 = n1 + n2
    }
    n, _ := strconv.Atoi(s[i-1:i+1])
    fmt.Printf("%d\n", n)
    if n >= 10 && n <= 26 {
      m2 = n1
    }
    n1, n2 = m1, m2
  }
  return n1 + n2
}
