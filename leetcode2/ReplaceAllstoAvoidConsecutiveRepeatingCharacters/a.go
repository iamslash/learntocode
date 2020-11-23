/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//            i
// s: ? ? y w ? i p k j ?
//    a b     

//          i
// s: j ? g ? ? b
//      a   a

// 0ms 100.00% 1.9MB 100.00%
// linear traversal
// O(N) o(N)
func modifyString(s string) string {
  n := len(s)
  ans := []byte(s)
  for i := 0; i < n; i++ {
    if ans[i] == '?' {
      for ans[i] = 'a'; ans[i] <= 'c'; ans[i]++  {
        if (i == 0 || ans[i-1] != ans[i]) &&
          (i == n-1 || ans[i] != ans[i+1]) {
          break
        }        
      }
    }
  }
  return string(ans)
}
