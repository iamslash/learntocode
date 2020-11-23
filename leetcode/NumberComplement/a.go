/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//  num: 0000 0101
//   bm: 1111 1000
//
// ~num: 1111 1010
//  ~bm: 0000 0111
//            0010

// 0ms 100.00% 2.1MB 50.00%
// bit manipulation
// O(1) O(1)
func findComplement(num int) int {
  bm := ^0
  for num & bm > 0 {
    bm <<= 1
  }
  return ^num & ^bm
}

func main() {
  fmt.Println("hello world")
}
