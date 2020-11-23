/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 95.53% 3.7Mb 100.00%
func shuffle(A []int, n int) []int {
  ans := make([]int, 2*n)
  for i := 0; i < n; i++ {
    j := i * 2;
    ans[j] = A[i];
    ans[j+1] = A[i+n];
  }
  return ans
}
