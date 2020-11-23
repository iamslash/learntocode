/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// math
// O(N) O(1)
func numWaterBottles(num int, div int) int {
  ans := num
  for num >= div {
    quo := num / div
    rem := num % div
    num = quo + rem
    ans += quo
  }
  return ans
}
