/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "unicode"
)

// 8ms 97.83% 6.1MB 100.00%
// backtracking
// O(2^N) O(N)
var rslt []string
func dfs(s []byte, i int) {
  // base
  if i == len(s) {
    rslt = append(rslt, string(s))
    return
  }
  // recursion
  if unicode.IsLetter(rune(s[i])) {
    s[i] = byte(unicode.ToLower(rune(s[i])))
    dfs(s, i+1)
    s[i] = byte(unicode.ToUpper(rune(s[i])))
  }
  dfs(s, i+1)
}
func letterCasePermutation(s string) []string {
  rslt = []string{}
  dfs([]byte(s), 0)
  return rslt
}

func main() {
  fmt.Println("hello world")
}
