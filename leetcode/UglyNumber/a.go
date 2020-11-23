/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 54.69% 2.2MB 50.00%
// math
// O(N) O(1)
func isUgly(num int) bool {
  if num == 0 {
    return false;      
  }
  if num == 1 {
    return true;
  }
  for num % 5 == 0 {
    num /= 5
  }
  for num % 3 == 0 {
    num /= 3
  }
  for num % 2 == 0 {
    num /= 2
  }
  return num == 1
}

func main() {
  fmt.Println(isUgly(14))
}
