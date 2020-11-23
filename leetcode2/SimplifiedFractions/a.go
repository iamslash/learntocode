/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4
//
// 1/2, 1/3, 2/3, 1/4, 3/4,
//
// 4 2
// 2 0

// 108ms 42.06% 6.6MB 65.26%
// math
// O(N^2) O(N)
func gcd(a, b int) int {
  if b == 0 {
    return a
  }
  return gcd(b, a%b)
}
func simplifiedFractions(n int) []string {
  ans := make([]string, 0)
  for j := 2; j <= n; j++ {
    for i := 1; i < j; i++ {
      if i == 1 || gcd(j, i) == 1 {
        ans = append(ans, fmt.Sprintf("%d/%d", i, j))
      }
    }
  }
  return ans;
}

