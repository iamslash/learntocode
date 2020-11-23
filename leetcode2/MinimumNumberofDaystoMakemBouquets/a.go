/* Copyright (C) 2020 by iamslash */

package main

// 128ms 63.64% 8.9MB 100.00%
// binary search
// O(NlgN) O(1)
func bouqCnt(D []int, day int, memCnt int) int {
	grpCnt, flower := 0, 0
	for i := 0; i < len(D); i++ {
		if D[i] > day {
			flower = 0
		} else {
			flower++
			if flower == memCnt {
				grpCnt++
				flower = 0
			}
		}
	}
	return grpCnt
}
func minDays(D []int, grpCnt int, memCnt int) int {
	if len(D) < grpCnt*memCnt {
		return -1
	}
	l, r, m := 1, 1000000009, 0
	for l < r {
		m = l + (r-l)/2
		if bouqCnt(D, m, memCnt) < grpCnt {
			l = m + 1
		} else {
			r = m
		}
	}
	return l
}
