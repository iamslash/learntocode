o/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//  price:  7 1 5 3 6 4
//   diff:  0-6 4-2 3-2
//   lmax:  0 0 4 2 5 3
//   gmax:  0 0 4 4 5 5

// 4ms 95.55% 3.1MB 25.00%
// kadane algorithm
// O(N) O(1)
func Max(a int, b int) int {
  if a > b {
    return a
  }
  return b
}

func maxProfit(P []int) int {
  lmax, gmax, n := 0, 0, len(P)
  for i := 1; i < n; i++ {
    lmax  = Max(0, lmax +  P[i] - P[i-1])
    gmax  = Max(gmax, lmax)
    //fmt.Printf("i: %d lmax: %d, gmax: %d\n", i, lmax, gmax)
  }
  return gmax
}

func main() {
	fmt.Println("hello world")
}
