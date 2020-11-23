/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//       s: abacb
// lastIdx: 24234
//            i
//     rst: ab 

// 0ms 100.00% 2.1MB 100.00%
// monotone increasing stack
// O(N^2) O(1)
func removeDuplicateLetters(s string) string {
  lastIdx := [26]int{}
  for i := range s {
    lastIdx[s[i] - 'a'] = i
  }
  seen := [26]bool{}
  var rst []rune
  for i, curRune := range s {
    for len(rst) > 0 && seen[curRune - 'a'] == false &&
      rst[len(rst) - 1] >= curRune &&
      lastIdx[rst[len(rst) - 1] - 'a'] >= i {
      seen[rst[len(rst) - 1] - 'a'] = false
      rst = rst[:len(rst)-1]
    }
    if seen[curRune - 'a'] == false {
      seen[curRune - 'a'] = true
      rst = append(rst, curRune)
    }
  }
  return string(rst)
}

func main() {
  fmt.Println(removeDuplicateLetters("abacb"))
}
