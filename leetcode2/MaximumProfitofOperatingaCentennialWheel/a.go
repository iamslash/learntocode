/* Copyright (C) 2020 by iamslash */

package main

// 120ms 100.00% 7.87MB 100.00%
// greedy algorithm
// O(N) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func minOperationsMaxProfit(customers []int, bcost int, rcost int) int {
	run, maxRun := 0, 1
	prof, maxProf := 0, 0
	sum, i, n := 0, 0, len(customers)
	for sum > 0 || i < n {
		if i < n {
			sum += customers[i]
			i++
		}
		boraded := min(4, sum)
		sum -= boraded
		prof = prof + boraded*bcost - rcost
		run++
		if prof > maxProf {
			maxProf = prof
			maxRun = run
		}
	}
	if maxProf <= 0 {
		return -1
	}
	return maxRun
}
