/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// h: 2
// w: 8
//                  i
// S: hello world hello world
//    01234567
//          01234567

// h: 6
// w: 1
//                i
// S: a b c a b c 
//    0
//      0
//        0  
//          0
//            0
//              0  

// skipping
// O(N) O(1)
func wordsTyping(S []string, h int, w int) int {
  line := ""
  for _, s := range S {
    line += s + " "
  }
  i, n := 0, len(line)
  for y := 0; y < h; y++ {
    i += w;
    if line[i % n] == ' ' {
      i++
    } else {
      for i > 0 && line[(i-1) %n] != ' ' {
        i--;
      }
    }
  }
  return i / n  
}
