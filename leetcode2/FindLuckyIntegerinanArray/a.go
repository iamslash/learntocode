/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// 4ms 95.28% 3MB 100.00%
// sort
// O(NlgN) O(1)
func findLucky(A []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(A)))
	i, j := 0, 0
	for i < len(A) {
		j = i
		for j < len(A) && A[i] == A[j] {
			j++
		}
		if A[i] == j-i {
			return A[i]
		}
		i = j
	}
	return -1
}
