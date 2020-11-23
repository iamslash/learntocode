/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//   i
// QQWE
//   j
//
// Q W E R
// 2 0 1 0
// k : 1
// r : 1

// i
// WWEQERQWQWWRWWERQWEQ
// j
//
// cnts: Q W E R
//       3 5 4 2
//    k: 1
//    r: 7

// 36ms 71.43% 3.2MB 100.00%
// CAUTION: substring
// sliding window
// O(N) O(1)
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func balancedString(s string) int {
  cnts := make(map[byte]int)
  n, r, i, k := len(s), len(s), 0, len(s)/4
  for j := 0; j < len(s); j++ {
      cnts[s[j]]++
  }
  for j := 0; j < len(s); j++ {
      cnts[s[j]]--
    for i < n && cnts['Q'] <= k && cnts['W'] <= k && cnts['E'] <= k && cnts['R'] <= k {
      r = min(r, j - i + 1)
      cnts[s[i]]++;
      i++
    }
  }
  return r
}

func main() {
  fmt.Println("hello world")
}
