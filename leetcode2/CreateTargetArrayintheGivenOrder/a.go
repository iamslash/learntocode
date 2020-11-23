/* Copyright (C) 2020 by iamslash */

package main

//             i
// idxs: 0 1 2 2 1
// vals: 0 1 2 3 4
//  ans: 0 1 2 3 0

// 0ms 100.00% 2.2MB 46.43%
// brute force
// O(NlgN) O(N)
func createTargetArray(vals []int, idxs []int) []int {
	n := len(vals)
	ans := make([]int, n)
	for i, idx := range idxs {
		copy(ans[idx+1:i+1], ans[idx:i])
		ans[idx] = vals[i]
	}
	return ans
}
