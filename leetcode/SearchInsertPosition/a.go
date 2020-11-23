/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// t: 5
//        i
// A: 1 3 5 6
//        m j
//

// binary search
// O(NlgN) O(1)
func searchInsert(A []int, t int) int {
  i, j, m := 0, len(A)-1, 0
  if A == nil || len(A) == 0 {
    return 0
  }
  if t > A[j] {
      return len(A)
  }
  
  for i < j {
    m = (i + j) / 2
    if (t > A[m]) {
      i += 1
    } else {
      j = m
    }
  }
  return i
}

func main() {
  A := []int{1, 3, 5, 6}
  t := 7
  fmt.Println(searchInsert(A, t))
}
