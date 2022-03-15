/* Copyright (C) 2022 by iamslash */

package main

import (
    "fmt"
    "sort"
)

// 12ms 54.12% 3.5MB 82.35%
// O(NlgN) O(1)
func findKthLargest(nums []int, k int) int {
    sort.Ints(nums)
    return nums[len(nums)-k]
}

func main() {
    fmt.Println("hello world")
}
