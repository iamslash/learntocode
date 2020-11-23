/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// 4ms 100.00% 3.9MB 26.32%
// sort
// O(NlgN) O(N)
func cntOne(a int) int {
	ans := 0
	for a > 0 {
		if a&1 == 1 {
			ans++
		}
		a >>= 1
	}
	return ans
}
func sortByBits(A []int) []int {
	n := len(A)
	oneCnts := make([]int, len(A))
	idxs := make([]int, len(A))
	for i := 0; i < n; i++ {
		idxs[i] = i
		oneCnts[i] = cntOne(A[i])
	}
	sort.Slice(idxs, func(i, j int) bool {
		if oneCnts[idxs[i]] == oneCnts[idxs[j]] {
			return A[idxs[i]] < A[idxs[j]]
		}
		return oneCnts[idxs[i]] < oneCnts[idxs[j]]
	})
	for i := 0; i < n; i++ {
		idxs[i] = A[idxs[i]]
	}
	return idxs
}
