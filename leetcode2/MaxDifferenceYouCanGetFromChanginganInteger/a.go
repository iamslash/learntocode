/* Copyright (C) 2020 by iamslash */

package main

import (
	"math"
	"strconv"
	"strings"
)

// 0ms 100.00% 2.1MB 20.00%
// brute force
// O(N) O(1)
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
func maxDiff(num int) int {
	s := strconv.Itoa(num)
	maxval, minval := math.MinInt32, math.MaxInt32
	for x := '0'; x <= '9'; x++ {
		for y := '0'; y <= '9'; y++ {
			u := strings.ReplaceAll(s, string(x), string(y))
			if strings.HasPrefix(u, "0") {
				continue
			}
			val, _ := strconv.Atoi(u)
			maxval = max(maxval, val)
			minval = min(minval, val)
		}
	}
	return maxval - minval
}
