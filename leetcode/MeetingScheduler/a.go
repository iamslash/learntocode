/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 120ms 50.00% 8.2MB 100.00%
// sort
// O(NlgN) O(N)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func minAvailableDuration(A [][]int, B [][]int, dur int) []int {
	sort.Slice(A, func(i, j int) bool {
		return A[i][0] < A[j][0]
	})
	sort.Slice(B, func(i, j int) bool {
		return B[i][0] < B[j][0]
	})
	for i, j := 0, 0; i < len(A) && j < len(B); {
		beg := max(A[i][0], B[j][0])
		end := min(A[i][1], B[j][1])
		if end-beg >= dur {
			return []int{beg, beg + dur}
		} else if A[i][1] < B[j][1] {
			i++
		} else {
			j++
		}
	}
	return []int{}
}

func main() {
	fmt.Println("hello world")
}
