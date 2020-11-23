/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "unicode"
)

// 0ms 100.00% 2.3MB 33.33%
// array
// O(NS) O(N)
func uniqueMorseRepresentations(W []string) int {
  table := []string{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}
  rslt := make(map[string]bool)
  for _, word := range W {
    var s string
    for _, char := range word {
      s += table[unicode.ToLower(char)-'a']
    }
    rslt[s] = true
  }
  return len(rslt)
}

func main() {
    fmt.Println("hello world")
}
