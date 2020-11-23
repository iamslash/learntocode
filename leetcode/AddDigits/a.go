/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// // 4ms 43.62% 2.2MB 100.00%
// // math
// // O(N) O(1)
// func addDigits(num int) int {
//   for num / 10 > 0 {
//     sum := 0
//     for num > 0 {
//       sum += num % 10
//       num /= 10
//     }
//     num = sum
//   }
//   return num
// }

// 0ms 100.00% 2.2MB 100.00%
// digit root
// O(1) O(1)
func addDigits(num int) int {
  return 1 + (num - 1) % 9
}

func main() {
  fmt.Println(addDigits(38))
}
