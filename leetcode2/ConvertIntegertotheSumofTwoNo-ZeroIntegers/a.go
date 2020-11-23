/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.1MB 100.00%
// brute force
// O(N) O(1)
func noZero(n int) bool {
  for n > 0 {
    d := n % 10
    if d == 0 {
      return false
    }
    n /= 10
  }
  return true
}
func getNoZeroIntegers(n int) []int {
  half := n / 2
  for a := 1; a <= half; a++ {
    b := n - a
    if noZero(a) && noZero(b) {
      return []int{a, b}
    }
  }
  return []int{}
}
