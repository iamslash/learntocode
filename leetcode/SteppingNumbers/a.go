/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// BFS
// O(N) O(N)
func countSteppingNumbers(low int, high int) []int {
  r := []int{}
  q := []int{}
  for i := 0 ; i < 10; i++ {
    q = append(q, i)
  }
  for len(q) > 0 {
    t := q[0]; q = q[1:]
    if t >= low && t <= high {
      r = append(r, t)
    }    
    if t < high {
      last := t % 10
      if last > 0 {
        q = append(q, t * 10 + last - 1)
      }
      if last < 9 {
        q = append(q, t * 10 + last + 1)        
      }
    }
  }
  return r
}

func main() {
  fmt.Println(countSteppingNumbers(3, 34))
}
