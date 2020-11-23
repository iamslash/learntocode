/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 86.27% 2.9MB 100.00%
func discount(P []int, i int) int {
  for j := i+1; j < len(P); j++ {
    if P[i] >= P[j] {
      return P[j]
    }
  }
  return 0
}
func finalPrices(P []int) []int {
  n := len(P)
  for i := 0; i < n-1; i++ {
    P[i] -= discount(P, i)
  }
  return P
}
