/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// O(N) O(1)
func climbStairs(n int) int {
  a, b := 1, 1
  for i := 2; i <= n; i++ {
    a, b = a + b, a
  }
  return a
}

func main() {
  fmt.Printf("%d\n", climbStairs(1))
  fmt.Printf("%d\n", climbStairs(2))
  fmt.Printf("%d\n", climbStairs(3))
  fmt.Printf("%d\n", climbStairs(5))
}
