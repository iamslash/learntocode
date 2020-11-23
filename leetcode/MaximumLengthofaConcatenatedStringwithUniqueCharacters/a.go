/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 44ms 30.77% 6.2MB 100.00%
// backtracking, bit manipulation
// O(16^N) O(N)
func max(a, b int) int {
  if a > b {
    return a
  }
  return b
}
func uniqueChars(a string) bool {
  ust := make(map[byte]int)
  for _, rune := range a {
    ust[byte(rune)]++
  }
  return len(ust) == len(a)
}
func dfs(A []string, s string, beg int) int {
  // base
  if len(s) > 0 && !uniqueChars(s) {
    return 0
  }
  // recursion
  maxChars := len(s)
  for i := beg; i < len(A); i++ {
    maxChars = max(maxChars, dfs(A, s+A[i], i+1))
  }
  return maxChars;
}
func maxLength(A []string) int {
  return dfs(A, "", 0)
}

func main() {
  A := []string{"un","iq","ue"}  
  fmt.Println(maxLength(A))
}
