/* Copyright (C) 2019 by iamslash */

package main

import "fmt"
import "bytes"

// 0ms 100.00% 2.2MB 100.00%
// hashmap
// O(N) O(1)
func longestPalindrome(s string) int {
  bs := []byte(s)
  odds := 0
  for b := 'A'; b <= 'z'; b++ {
    odds += bytes.Count(bs, []byte{byte(b)}) & 1
  }
  if odds > 0 {
    odds--
  }
  return len(s) - odds
}

func main() {
  fmt.Println(longestPalindrome("abccccdd"))
  fmt.Println(longestPalindrome("ccc"))
  fmt.Println(longestPalindrome("cccddd"))
}
