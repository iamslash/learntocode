/* Copyright (C) 2020 by iamslash */

package main

import "strings"
import "sort"

// 12ms 90.95% 5.9Mb 95.71%
// sort
// O(NlgN) O(1)
func arrangeWords(s string) string {
  ss := strings.Split(s, " ")
  ss[0] = strings.ToLower(ss[0])
  sort.SliceStable(ss, func (i, j int) bool {
    return len(ss[i]) < len(ss[j])
  })
  ans := strings.Join(ss, " ")
  return strings.ToUpper(ans[0:1]) + ans[1:]
}
