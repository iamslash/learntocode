/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 104ms 89.16% 203.1MB 50.00%
// brute force
// O(N) O(N)
func fizzBuzz(n int) []string {
  r := make([]string, n)
  for i := 0; i < n; i++ {
    r[i] = fmt.Sprintf("%d", i+1)
  }
  for i := 2; i < n; i += 3 {
    r[i] = "Fizz"
  }
  for i := 4; i < n; i += 5 {
    r[i] = "Buzz"
  }
  for i := 14; i < n; i += 15 {
    r[i] = "FizzBuzz"
  }
  return r
}

func main() {
  // fmt.Println([]string{"Hello","World","Good"})
  fmt.Println(fizzBuzz(15))
}
