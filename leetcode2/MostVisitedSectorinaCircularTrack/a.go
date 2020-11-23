/* Copyright (C) 2020 by iamslash */

package main

// s: R[0]
// e: R[len(R)-1]
// if s <= e
//   return [s..e]
// if s > e
//   return [1..e] + [s..n]

// 0ms 100.00% 2.7MB 87.93%
// math
// O(N) O(1)
func mostVisited(n int, R []int) []int {
	ans := []int{}
	for i := R[0]; i <= R[len(R)-1]; i++ {
		ans = append(ans, i)
	}
	if len(ans) > 0 {
		return ans
	}
	// [1..e]
	for i := 1; i <= R[len(R)-1]; i++ {
		ans = append(ans, i)
	}
	// [s..n]
	for i := R[0]; i <= n; i++ {
		ans = append(ans, i)
	}
	return ans
}
