/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 97.87% 4.5MB 100.00%
// matrix
// O(HW) O(1)
func isToeplitzMatrix(M [][]int) bool {
  if len(M) <= 1 {
    return true
  }
  for y := 1; y < len(M); y++ {
    for x := 1; x < len(M[0]); x++ {
      if M[y][x] != M[y-1][x-1] {
        return false
      }
    }    
  }
  return true
}

func main() {
    fmt.Println("hello world")
}
