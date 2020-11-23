/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 8 1 2 2 3
// 0 1 2 3 4
//
//         i
// 1 2 2 3 8
// 1 2 3 4 0
//         j
// 0 1 1 3 4

// 4ms 96.92% 3.6MB 10.17%
// two pointers
// O(N) O(N)
func smallerNumbersThanCurrent(A []int) []int {
	n := len(A)
	idx := make([]int, n)
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return A[idx[i]] < A[idx[j]]
	})
	fmt.Println(idx)
	for i, j := 0, 0; i < n; i++ {
		if i > 0 && A[idx[j]] < A[idx[i]] {
			j = i
		}
		ans[idx[i]] = j
	}
	return ans
}
