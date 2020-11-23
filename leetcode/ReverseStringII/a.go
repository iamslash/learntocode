/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 3.9MB 100.00%
// incremental method
// O(N) O(N)
func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
func reverse(r []rune, b, e int) {
  i, j := b, e
  for i < j {
    r[i], r[j] = r[j], r[i]
    i++
    j--
  }
}
func reverseStr(s string, k int) string {
  r := []rune(s)
  for i := 0; i < len(r); i += 2 * k {
    reverse(r, i, min(i + k - 1, len(r) -1))
  }
  return string(r)
}

func main() {
  fmt.Println("hello world")
}
