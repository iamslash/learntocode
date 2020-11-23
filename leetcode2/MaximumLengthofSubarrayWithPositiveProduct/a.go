/* Copyright (C) 2020 by iamslash */

package main

import "fmt"
import "math"

// // 96ms 81.93% 9.6MB 63.86%
// // memoization
// // O(N) O(1)
// func max(a, b int) int {
//   if a > b {
//     return a
//   }
//   return b
// }
// func getMaxLen(A []int) int {
//   beg, firstNeg, ans, negCnt, n := -1, -1, 0, 0, len(A)
//   for i := 0; i < n; i++ {
//     if A[i] < 0 {
//       negCnt++
//       if firstNeg == -1 {
//         firstNeg = i
//       }
//     } else if A[i] == 0 {
//       negCnt = 0
//       firstNeg = -1
//       beg = i
//     }
//     locMax := i - firstNeg
//     if negCnt & 1 == 0 {
//       locMax = i - beg
//     }
//     ans = max(ans, locMax)
//   }
//   return ans
// }

// //                          i
// //            A:    1 -2 -3 4
// //       negCnt:  0 0  1  2 2
// // firstEvenNeg: -1-1 -1 -1-1  
// //  firstOddNeg: -2-2  1  1 1
// //          ans:  0 1  1  3 4

// 172ms 16.87% 11MB 9.64%
func getMaxLen(A []int) int {
  n := len(A)
  posC := make([]int, n)  // 
  negC := make([]int, n)  // 
  if A[0] > 0 {
    posC[0] = 1
  } else if A[0] < 0 {
    negC[0] = 1
  } 
  for i := 1; i < n; i++ {
    if A[i] == 0 {
      continue
    }
    if A[i] > 0 {
      posC[i] = posC[i-1] + 1
      if negC[i-1] > 0 {
        negC[i] = negC[i-1] + 1
      }
    } else {
      negC[i] = posC[i-1] + 1
      if negC[i-1] > 0 {
        posC[i] = negC[i-1] + 1
      }
    }
  }  
  ans := 0
  for _, n := range posC {
    if n > ans {
      ans = n
    }
  }
  return ans
}
