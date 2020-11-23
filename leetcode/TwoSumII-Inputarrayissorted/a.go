/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// i
// 2 7 11 15
//   j

// i
// 5 25 75
//       j

// 4ms 95.38% 3MB 100.00%
// two pointers with shrinking
// O(N) O(1)
func twoSum(numbers []int, target int) []int {
  n := len(numbers)
  i, j := 0, n-1
  for numbers[i] + numbers[j] != target {
    if numbers[i] + numbers[j] < target {
      i++
    } else {
      j--
    }
  }
  return []int{i+1, j+1}  
}

func main() {
    fmt.Println("hello world")
}
