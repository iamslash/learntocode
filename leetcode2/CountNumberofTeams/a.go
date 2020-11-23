/* Copyright (C) 2020 by iamslash */

package main

// math
// O(N^2) O(1)
func numTeams(R []int) int {
	n, ans := len(R), 0
	for i := 1; i < n-1; i++ {
		lless, lgreat, rless, rgreat := 0, 0, 0, 0
		for j := 0; j < i; j++ {
			if R[j] < R[i] {
				lless++
			} else {
				lgreat++
			}
		}
		for j := i + 1; j < n; j++ {
			if R[i] > R[j] {
				rless++
			} else {
				rgreat++
			}
		}
		ans += lless*rgreat + lgreat*rless
	}
	return ans
}
