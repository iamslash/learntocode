/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 12ms 100.00% 5.7MB 100.00%
// linear traversal
// O(N) O(1)
func diagonalSum(M [][]int) int {
  n, ans := len(M), 0
  for i := 0; i < n; i++ {
    ans += M[i][i]
    ans += M[n-i-1][i]
  }
  if n & 1 > 0 {
    i := n / 2
    ans -= M[i][i]
  }
  return ans
}
