/* Copyright (C) 2019 by iamslash */

package main

import "fmt"
import "math"

// 0ms 100.00% 2.1MB 100.00%
// linear traversal
// O(N) O(1)
func average(S []int) float64 {
  min, max, sum := math.MaxInt32, math.MinInt32, 0
  for _, num := range S {
    sum += num
    if num < min {
      min = num
    }
    if num > max {
      max = num
    }
  }
  return float64(sum - min - max) / float64(len(S) - 2)
}
