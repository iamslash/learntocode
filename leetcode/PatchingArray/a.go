/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//     n: 5
//     A: 1 2 2
//              i
//  miss: 6
// added: 0


// 4ms 85.71$ 3.4MB 100.00%
// loop invariant: [1..miss] can express [1..2*miss)
// dynamic programming
// O(N) O(1)
func minPatches(A []int, n int) int {
  miss, added, i := 1, 0, 0
  for miss <= n {
    if i < len(A) && A[i] <= miss {
      miss += A[i]
      i++
    } else {
      miss += miss
      added++
    }
  }
  return added
}

func main() {
  fmt.Println("hello world")
}
