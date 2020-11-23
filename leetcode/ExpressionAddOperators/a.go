/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "strconv"
)

//   s: 123
// tgt: 6

//116ms 50.00% 11.2MB 100.00%
// backtracking
// O(3^N) O(N)
// cs: cumulative string
// cv: cumulative value
// pv: previous value
// po: previous operator
func dfs(r *[]string, s string, tgt int64, cs string, i int, cv int64, pv int64, po byte) {
  // fmt.Printf("i: %d, s: %s, cs: %s, r: %v\n", i, s, cs, r)
  // base
  if i == len(s) && cv == tgt {
    *r = append(*r, cs)
    return
  }
  // recursion
  for j := i + 1; j <= len(s); j++ {
    t := s[i:j]
    x, _ := strconv.Atoi(t)
    v := int64(x)
    tv := strconv.FormatInt(v, 10)    
    if len(t) != len(tv) {
      continue
    }
    dfs(r, s, tgt, cs+"+"+t, j, cv+v, v, '+')
    dfs(r, s, tgt, cs+"-"+t, j, cv-v, v, '-')
    var w int64
    if po == '-' {
      w = cv + pv - pv * v
    } else if po == '+' {
      w = cv - pv + pv * v
    } else {
      w = pv * v
    }
    dfs(r, s, tgt, cs+"*"+t, j, w, pv*v, po)
  }
}
func addOperators(s string, tgt int) []string {
  r := []string{}
  if len(s) == 0 {
    return r
  }
  for i := 1; i <= len(s); i++ {
    t := s[0:i]
    x, _ := strconv.Atoi(t)
    v := int64(x)
    tv := strconv.FormatInt(v, 10)
    if len(t) != len(tv) {
      continue
    }
    dfs(&r, s, int64(tgt), t, i, v, v, '#')
  }
  return r
}

func main() {
  fmt.Println(addOperators("105", 5))
}
