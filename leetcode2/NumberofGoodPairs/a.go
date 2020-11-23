/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// i
// 1 1 1 2 3 3
//       j

// 0ms 100.00% 2.1MB 100.00%
// sort
// O(NlgN) O(1)
func cumsum(a int) int {
	return a * (a - 1) / 2
}
func numIdenticalPairs(A []int) int {
	sort.Ints(A)
	i, j, n, ans := 0, 0, len(A), 0
	for i < n {
		j = i + 1
		for j < n && A[i] == A[j] {
			j++
		}
		if j-i > 0 {
			ans += cumsum(j - i)
		}
		i = j
	}
	return ans
}
