/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 44ms 64.71% 2MB 70.59%
// backtracking
// O(N^N) O(N)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func dfs(substrSet map[string]bool, s string) int {
  // base
  if s == "" {
    return 0
  }
  // recursion
  ans := 0
  for i := 1; i <= len(s); i++ {
    cand := s[:i]
    if _, ok := substrSet[cand]; ok {
      continue
    }
    substrSet[cand] = true
    ans = max(ans, 1 + dfs(substrSet, s[i:]))
    delete(substrSet, cand)
  }
  return ans
}
func maxUniqueSplit(s string) int {
  substrSet := make(map[string]bool)
  return dfs(substrSet, s)
}
