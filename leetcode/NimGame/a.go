/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// // Time Limit Exceeded
// // minimax
// // O(N) O(N)
// func canWinNim(n int) bool {
//   // base
//   if n <= 3 {
//     return true
//   }
//   // recursion
//   for i := 1; i <= 3; i++ {
//     if !canWinNim(n-i) {
//       return true
//     }
//   }
//   return false
// }

// 0ms 100.00% 1.9MB 100.00%
// minimax
// O(1) O(1)
func canWinNim(n int) bool {
  return n % 4 != 0
}

func main() {
  fmt.Println("hello world")
}
