/* Copyright (C) 2020 by iamslash */

package main

// 116ms 91.53% 13MB 25.42%
// dynamic programming
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxNonOverlapping(A []int, target int) int {
	cntMap := make(map[int]int)
	cntMap[0] = 0
	sum, ans := 0, 0
	for i := 0; i < len(A); i++ {
		sum += A[i]
		if _, ok := cntMap[sum-target]; ok {
			ans = max(ans, cntMap[sum-target]+1)
		}
		cntMap[sum] = ans
	}
	return ans
}
