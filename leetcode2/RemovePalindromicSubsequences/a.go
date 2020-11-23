/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// * s is consisted of 'a', 'b' !!!
// 0: length is 0
// 1: s is palindrome
// 2: others

// 0ms 100.00% 1.9MB 100.00%
// array
// O(N) O(1)
func palindrome(s string) bool {
  for i := 0; i < len(s); i++ {
    j := len(s) - 1 - i
    if s[i] != s[j] {
      return false
    }
  }
  return true
}
func removePalindromeSub(s string) int {
  if len(s) == 0 {
    return 0
  }
  if palindrome(s) {
    return 1
  }
  return 2
}
