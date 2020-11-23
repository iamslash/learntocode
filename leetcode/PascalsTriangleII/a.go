/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1

//  1 0 0 0 0
//  1 1 0 0 0
//  1 2 1
//  1 3 3 1
//  1 4 6 4 1

// 0ms 100.00% 2MB 100.00%
// array
// brute force
// O(N^2) O(N)
func getRow(idx int) []int {
  n := idx+1
  row := make([]int, n)
  row[0] = 1
  for i := 1; i < n; i++ {
    for j := i; j >= 1; j-- {
      row[j] += row[j-1]
    }
  }
  return row
}

func main() {
  fmt.Println("hello world")
}
