/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "strings"
)

// 4ms 97.74% 6.5MB 50.00%
// string
// O(N) O(N)
func repeatedSubstringPattern(s string) bool {
  ss := s + s
  return strings.Contains(ss[1:len(ss)-1], s)
}

func main() {
  fmt.Println("hello world")
}
