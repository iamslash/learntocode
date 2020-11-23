/* Copyright (C) 2020 by iamslash */

package main

// 0ms 100.00% 2.3MB 82.11%
// brute force
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func kidsWithCandies(candies []int, extraCandies int) []bool {
	ans := make([]bool, len(candies))
	maxCandy := 0
	for _, c := range candies {
		maxCandy = max(maxCandy, c)
	}
	for i := 0; i < len(candies); i++ {
		if candies[i]+extraCandies >= maxCandy {
			ans[i] = true
		}
	}
	return ans
}
