/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//                i
//     s: ( ( ) ) )
// right: 2 4 3 2 1
//   ans: 0 0 0 0 0

//            i
//     s: ) ) ) ) ) ) )
// right: 1 0 1 
//   ans: 1 1 1

// 12ms 76.74% 6.1MB 48.84%
// linear traversal
// O(N) O(1)
func minInsertions(s string) int {
  ans, right, n := 0, 0, len(s)
  for i := 0; i < n; i++ {
    if s[i] == '(' {
      if right & 1 > 0 {
        right--
        ans++
      }
      right += 2
    } else {
      right--
      if (right < 0) {
        right += 2
        ans++
      }
    }
  }
  return ans + right
}
