/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//  a: xxy
//  b: yxx
//       i
// 
// xy: 1
// yx: 1

// a: xxyyxyyx
// b: yxxyyxxy
// ignore same chars
//
// a: xyxyyx
// b: yxyxxy
// xy: 3, yx: 3
// swap 1 (xy, xy), ignore same chars
// 
// a: yyyx
// b: xxxy
// xy: 1, yx: 3
// swap 1 (yx, yx), ignore same chars
// 
// a: yx
// b: xy
// xy: 1, yx: 1
// swap 2 (yx, xy), ignore same chars
// 
// a: xy
// b: xy

// 0ms 100.00% 2MB 100.00%
// greedy
// O(N) O(1)
func minimumSwap(a string, b string) int {
  xy, yx := 0, 0
  for i := 0; i < len(a); i++ {
    if a[i] != b[i] && a[i] == 'x' {
      xy++
    }
    if a[i] != b[i] && a[i] == 'y' {
      yx++
    }
  }
  if (xy + yx) % 2 != 0 {
    return -1
  }
  return xy / 2 + yx / 2 + 2 * (xy % 2)
}

func main() {
    fmt.Println("hello world")
}
