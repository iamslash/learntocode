/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//
// m: 2
// A: 3 1 5 4 2
//
//    1 0 1 1 1

// m: 5
// A: 3 1 5 4 2
// 

//        m: 1
//                   i
//        A: 3 5 1 2 4
//           1 1 1 1 1
// length: 0 5 0 3 0 5 0

// 200ms 57.89% 9.5MB 92.98%
// hash map
// O(N) O(N)
func findLatestStep(A []int, m int) int {
  ans, n := -1, len(A)
  if n == m {
    return n
  }
  lengths  := make([]int, n+2)
  for i := 0; i < n; i++ {
    a := A[i]
    left := lengths[a - 1]
    right := lengths[a + 1]
    fmt.Printf("i: %d, a: %d, left: %d, right: %d\n", i, a, left, right)
    len := left + right + 1
    lengths[a - left] = len
    lengths[a + right] = len
    if left == m || right == m {
      ans = i
    }
    fmt.Println(lengths)
  }  
  return ans
}
