/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
// brute force
// O(N) O(1)
func checkRecord(s string) bool {
  nA, nL := 0, 0
  for _, b := range s {
    if b == 'A' {
      nL = 0
      nA ++
    } else if b == 'L' {
      nL++
    } else {
      nL = 0
    }
    if nA > 1 || nL > 2 {
      return false
    }
  }
  return true
}

func main() {
    fmt.Println("hello world")
}
