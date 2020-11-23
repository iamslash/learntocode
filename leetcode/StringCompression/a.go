/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//              i
// chars: a b 5 b b b c c c
//                    j
//                          k
//     

// 8ms 90.00% 6.5MB 100.00%
// two pointers
// O(N) O(1)
func compress(chars []byte) int {
  i, j, n := 0, 0, len(chars)
  for j < n {
    c := chars[j]
    cnt := 0
    for j < n && chars[j] == c {
      j++
      cnt++
    }
    chars[i] = c; i++
    if cnt > 1 {
      s := fmt.Sprintf("%d", cnt)
      for _, b := range []byte(s) {
        chars[i] = b
        i++
      }
    }
  }
  return i
}

func main() {
  B := []byte{'a','a','b'}
  fmt.Println(compress(B))
  fmt.Println(B)
}
