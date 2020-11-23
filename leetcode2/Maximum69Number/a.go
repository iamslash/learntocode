/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//i
// 9669
//  j 
//    9
//   69
//  669
// 9669

// string
// O(N) O(1)
func maximum69Number (num int) int {
  s := strconv.Itoa(num)
  s = strings.Replace(s, "6", "9", 1)
  n, _ := strconv.Atoi(s)
  return n
}
