/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//     i
// 1 3 0 3 12
//       j

// 68ms 48.88% 7.9Mb 80.00%
// two pointers
// O(N) O(1)
func moveZeroes(A []int)  {
  i, j, n := 0, 0, len(A)
  for j < n {
    if A[j] != 0 {
      A[i] = A[j]
      i++
    }
    j++
  }
  for k := i; k < n; k++ {
    A[k] = 0
  }
}

func main() {
  A := []int{0, 1, 0, 3, 12}
  moveZeroes(A)
  fmt.Println(A)
}
