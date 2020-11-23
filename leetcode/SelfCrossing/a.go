/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// There are just 2 cases for self crossing
//
// 0. b > 0 && d >= b && a >= c
// 1. b > 0 && d >= b && c - e <= a && c >= a && d - f <= b
// 
//            b                              b
//   +----------------+             +----------------+
//   |                |             |                |
//   |                |             |                | a
// c |                |           c |                |
//   |                | a           |                |    f
//   +----------->    |             |                | <----+
//            d       |             |                |      | e
//                    |             |                       |
//                                  +-----------------------+
//                                               d

// 0ms 100.00% 2MB 100.00%
// computational geometry
// O(N) O(1)
func isSelfCrossing(x []int) bool {
  a, b, c, d, e, f := 0, 0, 0, 0, 0, 0
  for _, i := range x {
    a, b, c, d, e, f = i, a, b, c, d, e
    if d >= b && b > 0 &&
      (a >= c || c - e <= a && c >= e && d - f <= b) {
      return true
    }
  }
  return false
}

func main() {
    fmt.Println("hello world")
}
