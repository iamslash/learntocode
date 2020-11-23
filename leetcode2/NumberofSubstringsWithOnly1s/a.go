/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 90.44% 4.3MB 83.82%
// math
// O(N) O(1)
func numSub(s string) int {
  mod := 1000000007
  n, ans, cnt := len(s), 0, 0
  for i := 0; i < n; i++ {
    if s[i] == '0' {
      cnt = 0
    } else {
      cnt++
    }
    ans = (ans + cnt) % mod
  }
  return ans
}
