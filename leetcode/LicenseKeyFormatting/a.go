/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "strings"
)


// s: 5F3Z-2e-9-w
// k: 4
//              -2E9W

// 4ms 90.60% 5.4MB 100.00%
// reverse
// O(N) O(N)
func reverse(s string) string {
  bytes := []byte(s)
  for i, j := 0, len(bytes)-1; i < j; i, j = i+1, j-1 {
    bytes[i], bytes[j] = bytes[j], bytes[i]
  }
  return string(bytes)
}
func licenseKeyFormatting(s string, k int) string {
  
  sb := strings.Builder{}
  for i := len(s) - 1; i >= 0; i-- {
    if s[i] != '-' {
      if sb.Len() % (k+1) == k {
        sb.WriteRune('-')
      }
      sb.WriteByte(s[i])
    }
  }

  return strings.ToUpper(reverse(sb.String()))
}

func main() {
  fmt.Println("hello world")
}
