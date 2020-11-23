/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// C[i][j] = probability until i-th coins with j heads
//         = Prob until i-1 th coins with   j heads * Prob i th coins with back +
//           Prob until i-1 th coins with j-1 heads * Prob i th coins with head
// C[0][0] = 1
// C[i][j] = C[i-1][j-1] * P[i] + C[i-1][j] * (1 - P[i])
//
// P: [0.4, 0.8]
// T: 1
//
//      0    1
// 0  1.0    0
// 1  0.4 0.24
// 2 0.08 

// 20ms 83.33% 12.6MB 100.00%
// dynamic programming
// O(NT) O(NT)
func probabilityOfHeads(P []float64, T int) float64 {
  C := make([][]float64, len(P)+1)
  for i := 0; i < len(C); i++ {
    C[i] = make([]float64, T+1)
  }
  C[0][0] = 1.0
  for i := 1; i < len(C); i++ {
    C[i][0] = C[i-1][0] * (1 - P[i-1])
  }
  for i := 1; i < len(C); i++ {
    for j := 1; j < len(C[i]); j++ {
      C[i][j] = C[i-1][j-1] * P[i-1] + C[i-1][j] * (1-P[i-1])
    }
  }
  return C[len(P)][T]
}

func main() {
  fmt.Println("hello world")
}
