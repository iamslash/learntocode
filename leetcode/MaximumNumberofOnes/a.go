/* Copyright (C) 2019 by iamslash */

package main

import (
  "fmt"
  "sort"
)

// 8ms 100.00% 4.2MB 100.00%
// math
// O(NlgN) O(N)
func maximumNumberOfOnes(w int, h int, s int, maxone int) int {
  rec := make([]int, 0)
  for i := 0; i < s; i++ {
    for j := 0; j < s; j++ {
      r := (h - i - 1) / s + 1
      c := (w - j - 1) / s + 1
      rec = append(rec, r * c)
    }
  }
  sort.Sort(sort.Reverse(sort.IntSlice(rec)))
  ans := 0
  for i := 0; i < maxone; i++ {
    ans += rec[i]
  }
  return ans
}

func main() {
  a := []int{5, 4, 3, 1, 2}
  // sort.Sort(sort.Reverse(sort.IntSlice(a)))
  sort.Reverse(sort.IntSlice(a))
  fmt.Println(a)
}
