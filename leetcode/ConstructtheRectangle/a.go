/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "math"
)

// 0ms 100.00% 1.9MB 100.00%
// math
// O(N) O(1)
func constructRectangle(area int) []int {
  for mid := int(math.Sqrt(float64(area))); mid > 0; mid-- {
    if area % mid == 0 {
      return []int{area/mid, mid}
    }
  }

  return []int{}
}

func main() {
  fmt.Println("hello world")
}
