/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 24ms 96.43% 7.6MB 100.00%
// gray code
// O(N) O(1)
func circularPermutation(n int, s int) []int {
  rslt := []int{}
  for i := 0; i < (1 << n); i++ {
    rslt = append(rslt, s ^ i ^ (i >> 1))
  }
  return rslt
}

func main() {
    fmt.Println(circularPermutation(2, 3))
}
