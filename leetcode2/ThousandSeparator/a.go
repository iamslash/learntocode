/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
// math
// O(N) (1)
func thousandSeparator(n int) string {
  if n == 0 {
    return "0"
  }
  ans := ""
  for n > 0 {
    rem := n % 1000;
    n   = n / 1000;
    remStr := fmt.Sprintf("%d", rem)
    if n > 0 {
      remStr = fmt.Sprintf(".%0.3d", rem)
    }
    ans = remStr + ans
  }
  return ans
}
