/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
)

// 0ms 100.00% 1.9MB 100.00%
// bit manipulation
// O(1) O(1)
func toHex(num int) string {
  if num == 0 {
    return "0"
  }
  digits := [16]byte{'0','1','2','3','4','5',
    '6','7','8','9','a','b','c','d','e','f'}
	r, d := []byte{}, 0
  for i := 0; i < 8 && num != 0; i++ {
    d = num & 0x0F
    r = append([]byte{digits[d]}, r...)
    num >>= 4
  }
  return string(r)
}

func main() {
	fmt.Println(toHex(1))
	fmt.Println(toHex(26))
	fmt.Println(toHex(27))
	fmt.Println(toHex(-1))
}
