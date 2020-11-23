/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// t: 9
//    i
// A: 3 5 6 7
//          j

// math
// O(N) O(N)
// 140ms 79.37% 8.9MB 26.98%
var MAXVAL int = 1000000007

func buildPow(P []int, n int) {
	P[0] = 1
	for i := 1; i < n; i++ {
		P[i] = (P[i-1] * 2) % MAXVAL
	}
}
func numSubseq(A []int, tgt int) int {
	sort.Ints(A)
	n := len(A)
	P := make([]int, n+1)
	buildPow(P, n)
	i, j, ans := 0, n-1, 0
	for i <= j {
		if A[i]+A[j] > tgt {
			j--
		} else {
			ans = (ans + P[j-i]) % MAXVAL
			i++
		}
	}
	return ans
}
