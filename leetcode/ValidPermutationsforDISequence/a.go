/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 4MB 100.00%
// dynamic programming
// O(N^2) O(N^2)
func numPermsDISequence(s string) int {
  const MOD = 1e9 + 7
  var n = len(s)
  var C = make([][]int, n+1)
  for i := range C {
    C[i] = make([]int, n+1) 
  }
  for i := range C[0] {
    C[0][i] = 1
  }
  // fmt.Println(C)
  for i := 0; i < n; i++ {
    if s[i] == 'I' {
      for j, k := 0, 0; j < n-i; j++ {
        C[i+1][j] = (k + C[i][j]) % MOD
        k = C[i+1][j]
      }
    } else {
      for j, k := n-i-1, 0; j >= 0; j-- {
        C[i+1][j] = (k + C[i][j+1]) % MOD
        k = C[i+1][j]        
      }
    }
  }  
  return C[n][0];
}

func main() {
  // fmt.Println(numPermsDISequence("DID"))
  fmt.Println(1e1)
  fmt.Println(10e1)  
}
