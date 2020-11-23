/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//          i
//   s:   a b c
// pre: 0 1 2 4 
// ans: 1 2 4 8
// end: a b c
//      1 2 4

//            i
//   s:   a a a
// pre: 0 1 2 3 
// ans: 1 2 3 4
// end: a 
//      3 

// 0ms 100.00% 2.1MB 100.00%
// iterative dynamic programming
// O(N) O(1)
func distinctSubseqII(s string) int {
  ans, MOD := 1, 1000000007
  end := make([]int, 26)
  for i := 0; i < len(s); i++ {
    c := s[i]
    pre := ans;
    ans = (ans * 2 % MOD - end[c - 'a'] + MOD) % MOD
    end[c - 'a'] = pre
  }
  return ans - 1
}
