/* Copyright (C) 2020 by iamslash */

package main

import "math"

//             i
//      s:   0 0 1 1 1
// psZero: 0 1 2 2 2 2
//  psOne: 0 0 0 1 2 3

// 0ms 100.00% 2.3MB 11.43%
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxScore(s string) int {
	n := len(s)
	pszero := make([]int, n+1)
	psone := make([]int, n+1)
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			pszero[i+1] = 1
		} else {
			psone[i+1] = 1
		}
		pszero[i+1] += pszero[i]
		psone[i+1] += psone[i]
	}
	score := math.MinInt32
	for i := 0; i < n-1; i++ {
		score = max(score, pszero[i+1]+psone[n]-psone[i+1])
	}
	return score
}
