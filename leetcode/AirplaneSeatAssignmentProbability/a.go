/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// math, brain teaser
// O(1) O(1)
func nthPersonGetsNthSeat(n int) float64 {
  if n > 1 {
    return 1.0
  }
  return 0.5
}

func main() {
  fmt.Println("hello world")
}
