/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 16ms 86.02% 6.3MB 100.00%
// brute force
// O(N) O(1)
func palindrome(s string, i, j int) bool {
  for i < j {
    if s[i] != s[j] {
      return false
    }
    i++
    j--
  }
  return true
}
func validPalindrome(s string) bool {
  for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
    if s[i] != s[j] {
      return palindrome(s, i, j-1) ||
        palindrome(s, i+1, j)
    }
  }
  return true
}

func main() {
    fmt.Println("hello world")
}
