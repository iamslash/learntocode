/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//            i
//    s: leEeetcode
// stck: leet

//            i
//    s: abBAcC
// stck: 

// 0ms 100.00% 2.2MB 100.00%
// stack
// O(N) O(1)
func makeGood(s string) string {
  stck := []byte{}
  for i := 0; i < len(s); i++ {
    if len(stck) > 0 &&
      (stck[len(stck)-1] == s[i] + 32 ||
      stck[len(stck)-1]+32 == s[i]) {
      stck = stck[:len(stck)-1]
    } else {
      stck = append(stck, s[i])
    }
  }
  return string(stck)
}
