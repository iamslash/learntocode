/* Copyright (C) 2020 by iamslash */

package main

// 0 1 1 0    0 0 0 0
// 0 1 1 1    0 0 0 0
// 1 1 1 0    0 0 0 0

// 20ms 98.28% 6.1MB 91.38%
// array
// O(HW^2) O(W)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func numSubmat(M [][]int) int {
	h, w, ans := len(M), len(M[0]), 0
	H := make([]int, w)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if M[y][x] == 0 {
				H[x] = 0
			} else {
				H[x] += 1
			}
			for k, minH := x, H[x]; k >= 0 && minH > 0; k-- {
				minH = min(minH, H[k])
				ans += minH
			}
		}
	}
	return ans
}
