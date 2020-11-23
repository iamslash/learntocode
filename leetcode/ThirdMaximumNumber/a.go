/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
  "math"
)

// 4ms 93.55% 3MB 100.00%
// brute force
// O(N) O(1)
func thirdMax(nums []int) int {
  a, b, c := math.MinInt64, math.MinInt64, math.MinInt64
  for _, n := range nums {
    if n <= c || n == b || n == a {
      continue
    }
    c = n
    if c > b {
      b, c = c, b
    }
    if b > a {
      a, b = b, a
    }
  }
  if c == math.MinInt64 {
    return a
  }
  return c
}

func main() {
  fmt.Println("hello world")
}
