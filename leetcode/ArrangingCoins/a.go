/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
  // "math"
)

// 0
// 0 1
// 0 1 2
// 0 1 2 3
// 0 1 2 3 4

// // 12ms 9.80% 2.2MB 100.00%
// // brute force
// // O(N) O(1)
// func arrangeCoins(n int) int {
//   r := 0

//   for i := 0; i < n; i++ {
//     r++
//     i += r
//   }

//   return r
// }

// 4ms 68.63% 2.2MB 100.00%
// binary search
// O(lgN) O(1)
func arrangeCoins(n int) int {
  l, m, h := 0, 0, n
  for l < h {
    m = l + (h-l+1)/2
    if (1 + m) * m / 2 <= n {
      l = m
    } else {
      h = m - 1
    }
  }
  return l
}


// n = 1 + 2 + 3 + ... + x 
//   = x * (x + 1) / 2
//   = (x^2 + x) / 2
//
//       x^2 + x = 2n
//   (x + 1/2)^2 = 2n + 1/4
//       x + 0.5 = sqrt(2n + 1/4)
//             x = -0.5 + sqrt(2n + 0.25)

// // 4ms 68.63% 2.2MB 100.00%
// // math
// // O(1) O(1)
// func arrangeCoins(n int) int {
//   return int(-0.5 + math.Sqrt(float64(2 * n) + 0.25))
// }

func main() {
  // for i := 0; i < 10; i++ {
  //   fmt.Println(arrangeCoins(i))
  // }
  fmt.Println(arrangeCoins(8))
}
