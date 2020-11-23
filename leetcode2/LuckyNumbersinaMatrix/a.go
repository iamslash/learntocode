/* Copyright (C) 2020 by iamslash */

package main

import "math"

//  3  7  8
//  9 11 13
// 15 16 17

// 20ms 57.89% 6MB 95.24%
// hash map
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func luckyNumbers(M [][]int) []int {
	h, w := len(M), len(M[0])
	rows := make([]int, h)
	cols := make([]int, w)
	for i := 0; i < h; i++ {
		rows[i] = math.MaxInt32
	}
	for i := 0; i < w; i++ {
		cols[i] = math.MinInt32
	}
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			cols[x] = max(cols[x], M[y][x])
			rows[y] = min(rows[y], M[y][x])
		}
	}
	rowNumSet := make(map[int]bool)
	for y := 0; y < h; y++ {
		rowNumSet[rows[y]] = true
	}
	ans := []int{}
	for x := 0; x < w; x++ {
		if _, ok := rowNumSet[cols[x]]; ok {
			ans = append(ans, cols[x])
		}
	}
	return ans
}
