/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 4.2MB 100.00%
// dynamic programming
// O(N^2) O(N^2)
const DIV = 1000000007
func dieSimulator(n int, rollMax []int) int {
  C := make([][]int64, n)
  for i := 0; i < n; i++ {
    C[i] = make([]int64, 7)
  }
  for j := 0; j < 6; j++ {
    C[0][j] = 1
  }
  C[0][6] = 6
  for i := 1; i < n; i++ {
    var sum int64 = 0
    for j := 0; j < 6; j++ {
      C[i][j] = C[i-1][6]
      if i - rollMax[j] == 0 {
        C[i][j] = (C[i][j] - 1) % DIV
      } else if i - rollMax[j] > 0 {
        C[i][j] = (C[i][j] - (C[i-rollMax[j]-1][6] - C[i-rollMax[j]-1][j])) % DIV + DIV
      }
      sum = (sum + C[i][j]) % DIV
    }
    C[i][6] = sum
  }
  
  return int(C[n-1][6])
}

func main() {
    fmt.Println("hello world")
}
