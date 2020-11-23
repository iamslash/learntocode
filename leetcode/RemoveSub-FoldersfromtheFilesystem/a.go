/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "sort"
  "strings"
)

// 48ms 100.00% 10.3MB 100.00%
// sort
// O(NlgN) O(N)
func removeSubfolders(F []string) []string {
  rslt := []string{}
  sort.Strings(F)
  for i := 0; i < len(F); i++ {
      if len(rslt) == 0 || !strings.HasPrefix(F[i], rslt[len(rslt)-1] + "/") {
      rslt = append(rslt, F[i])
    }
  }
  return rslt;
}

func main() {
  fmt.Println("hello world")
}
