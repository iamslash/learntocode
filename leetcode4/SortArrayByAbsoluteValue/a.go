/* Copyright (C) 2025 by iamslash */

package main

import "fmt"

// 0ms 100.00% 6.12MB 44.44%
// sort
// O(NlgN) O(1)
func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}

func sortByAbsoluteValue(nums []int) []int {
    sort.Slice(nums, func(i, j int) bool {
        return abs(nums[i]) < abs(nums[j])
    });

    return nums
}

func main() {
    fmt.Println("hello world")
}
