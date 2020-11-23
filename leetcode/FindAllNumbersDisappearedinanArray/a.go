/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// A: 4 3 2 7 8 2 3 1
//          

// 420ms 18.07% 8.2MB 100.00%
// trailing
// O(N) O(1)
func abs(a int) int {
  if a < 0 {
    return -a
  }
  return a
}
func findDisappearedNumbers(A []int) []int {
  rst := []int{}
  for i := 0; i < len(A); i++ {
    if idx := abs(A[i])-1; A[idx] > 0 {
      A[idx] *= -1
    }
  }
  for i := 0; i < len(A); i++ {
    if A[i] > 0 {
      rst = append(rst, i+1)
    }
  }
  return rst
}

func main() {
  A := []int{4, 3, 2, 7, 8, 2, 3, 1}
  fmt.Println(findDisappearedNumbers(A))
}
