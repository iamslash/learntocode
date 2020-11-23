/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//              i
// s: Hello World

// 0ms 100.00% 2.2MB 33.33%
// O(N) O(1)
func lengthOfLastWord(s string) int {
  n := len(s)
  i := n - 1
  
  for i >= 0 && s[i] == ' ' {
    i--
    n--
  }
  for i >= 0 && s[i] != ' ' {
    i--
  }
  return n - i - 1
}

func main() {
  // s := "Hello World"
  // s := "HelloWorld"
  s:= "a "
  fmt.Println(lengthOfLastWord(s))
}
