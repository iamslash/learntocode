/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// 4ms 96.88% 3.6MB 6.45%
// sort
// O(NlgN) O(N)
func minSubsequence(A []int) []int {
	idx := make([]int, len(A))
	all := 0
	for i := 0; i < len(A); i++ {
		idx[i] = i
		all += A[i]
	}
	half := all / 2
	sort.Slice(idx, func(i, j int) bool {
		return A[idx[i]] > A[idx[j]]
	})
	ans := []int{}
	sum := 0
	for i := 0; i < len(idx) && sum <= half; i++ {
		sum += A[idx[i]]
		ans = append(ans, idx[i])
	}
	// fmt.Println(ans)
	sort.Slice(ans, func(i, j int) bool {
		return A[ans[i]] > A[ans[j]]
	})
	for i := 0; i < len(ans); i++ {
		ans[i] = A[ans[i]]
	}
	return ans
}
