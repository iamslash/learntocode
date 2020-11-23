/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 1 2 2 4
// 2
//
// ans[0] = a
// ans[1] = a ^ b
// ans[1] = ans[0] ^ ans[1]

// 24ms 96.97% 6.2MB 100.00%
// XOR
// O(N) O(1)
func abs(a int) int {
  if a < 0 {
    return -a
  }
  return a
}
func findErrorNums(A []int) []int {
  ans := []int{0, 0}
  for i := 0; i < len(A); i++ {
    val := abs(A[i])
    ans[1] ^= (i+1) ^ val
    if A[val-1] < 0 {
      ans[0] = val
    } else {
      A[val-1] = -A[val-1]
    }    
  }
  ans[1] ^= ans[0]
  return ans
}

func main() {
    fmt.Println("hello world")
}
