/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "math"
)

// A: -1
// k:  1

// 124ms 85.45% 6.8MB 100.00%
// sliding window
// O(N) O(1)
func findMaxAverage(A []int, k int) float64 {
  maxAvg := -float64(math.MaxFloat64)
  var sum float64 = 0.0
  for i, num := range A {
    sum += float64(num)
    if i + 1 >= k {
      maxAvg = math.Max(maxAvg, sum / float64(k))
      // fmt.Printf("%f %f %f\n", sum, sum / float64(k), maxAvg)
      sum -= float64(A[i+1-k])
    }
  }
  return maxAvg
}

func main() {
  fmt.Println(findMaxAverage([]int{-1}, 1))
}
