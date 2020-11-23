/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// bnd: 1
//   m: 1
//          p
//   P: 1 2 3 4 7
//            i

// 180ms 74.24% 9.1MB 65.15%
// binary search
// O(NlgN) O(1)
func valid(P []int, m, sep int) bool {
	cur, ans := 0, 1
	for i := 0; i < len(P)-1; i++ {
		cur += P[i+1] - P[i]
		if cur >= sep {
			ans++
			cur = 0
		}
	}
	return ans >= m
}
func maxDistance(P []int, m int) int {
	sort.Ints(P)
	lo, hi, mi := 1, 999999999, 0
	for lo < hi {
		mi = (lo + hi + 1) / 2
		if valid(P, m, mi) {
			lo = mi
		} else {
			hi = mi - 1
		}
	}
	return lo
}

//    l
// A: 1 2 3 4 5 6 7 8 9
//                    h
//            m
//    l

// A: 1 2 3 4 5 6 7 8
//                  h
//          m

// m: 3
// P: 1 2 3 4 7
//    l
// A: 1 2 3 4 ... 999999999
//                        h
//        m
//
