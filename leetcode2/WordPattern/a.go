/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "strings"
)

// ptn: abba
// str: dog dog dog dog

// 0ms 100.00% 2MB 75.00%
// hash
// O(N) O(N)
func wordPattern(ptns string, str string) bool {
  ptn2wrd := make(map[byte]string)
  wrd2ptn := make(map[string]byte)
  
  words := strings.Split(str, " ")
  if len(ptns) != len(words) {
    return false
  }
  for i := 0; i < len(ptns); i++ {
    u, v := ptns[i], words[i]
    
    if wrd, ok := ptn2wrd[u]; ok {
      if wrd != v || wrd2ptn[wrd] != u {
        return false
      }
    } else if ptn, ok := wrd2ptn[v]; ok {
      if ptn != u || ptn2wrd[ptn] != v {
        return false
      }
    } else {
      ptn2wrd[u] = v
      wrd2ptn[v] = u 
    }
  }
  return true
}

func main() {
  fmt.Println("hello world")
}
