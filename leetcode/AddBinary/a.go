/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
)

// 0ms 100.00% 2.8MB 25.00%
// O(max(A,B)) O(max(A,B))
func addBinary(a string, b string) string {
  r := ""
  i, j, c := len(a) - 1, len(b) - 1, 0
  for i >= 0 || j >= 0 {
    if i >= 0 {
      c += int(a[i] - '0')
      i--
    }
    if j >= 0 {
      c += int(b[j] - '0')
      j--
    }
    
    if len(r) == 0 {
      r = fmt.Sprintf("%d", c % 2)
    } else {
      r = fmt.Sprintf("%d%s", c % 2, r)
    }
    c /= 2
    // fmt.Printf("%d %d \n", i, j)
  }
  if c > 0 {
    r = fmt.Sprintf("%d%s", c, r)
  }
  return r
}

func main() {
  a := "1010"
  b := "1011"
  fmt.Println(addBinary(a, b))
}
