/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 4ms 67.90% 7.1MB 60.00%
// brute force
// O(N) O(N)
func max(a int, b int) int {
  if a > b {
    return a
  }
  return b
}
func addStrings(a string, b string) string {
  c, m, n, r := 0, len(a), len(b), []byte{}
  for i, j := m-1, n-1;
    i >= 0 || j >= 0 || c > 0 ;
    i, j = i-1, j-1 {
      x := 0
      if i >= 0 {
        x = int(a[i] - '0')
      }
      y := 0
      if j >= 0 {
        y = int(b[j] - '0')
      }
      r = append([]byte{byte('0' + (x+y+c)%10)}, r...)
      c = (x+y+c)/10
  }
  return string(r)
}

func main() {
  fmt.Println(addStrings("1", "123"))
}
