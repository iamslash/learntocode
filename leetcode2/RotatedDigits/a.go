/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0 1 2 3 4 5 6 7 8 9
// 0 1   x x     x 8 
//     5     2 9     6 

// 0ms 100.00% 1.9MB 100.00%
// brute force
// O(NlgN) O(lgN)
func good(n int, flag bool) bool {
  // base
  if n == 0 {
    return flag
  }
  d := n % 10
  if d == 3 || d == 4 || d == 7 {
    return false
  }
  // recursion
  if d == 0 || d == 1 || d == 8 {
    return good(n/10, flag)
  }
  return good(n/10, true)  
}
func rotatedDigits(N int) int {
  ans := 0
  for i := 1; i <= N; i++ {
    if good(i, false) {
      ans++
    }
  }
  return ans
}

func main() {
  fmt.Println("hello world")
}
