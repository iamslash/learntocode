/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "sort"
)

// 60ms 94.07% 6.4MB 100.00%
// sort
// O(NlgN) O(1)
func arrayPairSum(A []int) int {
  rslt := 0
  sort.Ints(A)
  for i := 0; i < len(A); i += 2 {
    rslt += A[i]
  }
  return rslt
}

func main() {
  fmt.Println("hello world")
}
