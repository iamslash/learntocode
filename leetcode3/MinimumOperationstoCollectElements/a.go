/* Copyright (C) 2023 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.5MB 61.32%
// hash set
// O(N) O(N)
func minOperations(nums []int, k int) int {
    var n = len(nums)
    var numSet = make(map[int]struct{})
    for i := n - 1; i >= 0; i-- {
        if nums[i] <= k {
            numSet[nums[i]] = struct{}{}
        }
        if len(numSet) == k {
            return n - i
        }
    }
    return -1
}

func main() {
    fmt.Println("hello world")
}
