/* Copyright (C) 2020 by iamslash */

package main

// math
// O(1) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func getLastMoment(n int, L, R []int) int {
	units := 0
	for _, l := range L {
		units = max(units, l)
	}
	for _, r := range R {
		units = max(units, n-r)
	}
	return units
}
