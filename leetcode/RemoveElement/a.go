/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//          i
// A: 3 3 2 2
//        s

// 0ms 100.00% 2.4MB 66.67%
// O(N) O(1)
func removeElement(nums []int, val int) int {
  if nums == nil || len(nums) == 0 {
    return 0
  }
  s := 0
  for i := 0; i < len(nums); i++ {
    if nums[i] != val {
      nums[s] = nums[i]
      s++
    }
  }
  return s
}

func main() {
  // nums := []int{1}
  nums := []int{3, 2, 2, 3}
  val  := 2
  fmt.Printf("%d\n", removeElement(nums, val))
}
