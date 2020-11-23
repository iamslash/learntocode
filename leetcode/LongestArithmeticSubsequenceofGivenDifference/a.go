/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 112ms 53.33% 8.8MB 100.00%
// hash map
// O(N) O(N)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func longestSubsequence(A []int, diff int) int {
  dic := map[int]int{}
  r := 1
  for _, i := range A {
    dic[i] = dic[i - diff] + 1
    r = max(r, dic[i])
  }
  return r
}

func main() {
  fmt.Println("hello world")
}
