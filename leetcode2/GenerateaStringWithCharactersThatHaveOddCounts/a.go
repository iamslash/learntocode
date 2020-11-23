/* Copyright (C) 2020 by iamslash */

package main

import "fmt"
// 7
// 3 4
//
// 4
// 1 3
// 8
// 4 4

// 0ms 100.00% 2.2MB 44.44%
func generate(i, n int) string {
  // base
  if n == 0 {
    return ""
  }
  // recursion
  half := n/2
  s := string('a'+i)
  if half & 1 == 0 {
    half++
  }
  return strings.Repeat(s, half) + generate(i+1, n-half)
}
func generateTheString(n int) string {
  return generate(0, n)
}
