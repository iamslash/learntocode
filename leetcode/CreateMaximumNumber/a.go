/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//       i
// A = 3 9
// B = 8 9
//     
//
// k = 3

// 8ms 100.00% 6.2MB 100.00%
// greedy
// O((A+B)^3) O(A+B)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func maxArray(A []int, cnt int) []int {
  n := len(A)
  ans := make([]int, cnt)
  for i, j := 0, 0; i < n; i++ {
    for n - i + j > cnt && j > 0 && ans[j - 1] < A[i] {
      j--
    }
    if j < cnt {
      ans[j] = A[i]
      j++
    }
  }
  return ans
}
// A is greater than B ?
func greater(A []int, B []int, i, j int) bool {
  for i < len(A) && j < len(B) && A[i] == B[j] {
    i++; j++
  }
  return j == len(B) || (i < len(A) && A[i] > B[j])
}
// return merged array with A, B whose count is k
func merge(A []int, B []int, k int) []int {
  ans := make([]int, k)
  for i, j, r := 0, 0, 0; r < k; r++ {
    if greater(A, B, i, j) {
      ans[r] = A[i]
      i++
    } else {
      ans[r] = B[j]
      j++
    }
  }
  return ans;
}
func maxNumber(A []int, B []int, k int) []int {
  m := len(A)
  n := len(B)
  ans := make([]int, k)
  for cntA := max(0, k - n); cntA <= k && cntA <= m; cntA++ {
    cand := merge(maxArray(A, cntA), maxArray(B, k - cntA), k)
    if greater(cand, ans, 0, 0) {
      ans = cand
    }
  }
  return ans
}

func main() {
    fmt.Println("hello world")
}
