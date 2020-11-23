/* Copyright (C) 2020 by iamslash */

package main

//              l
//              i
//    A: 1 2 3 10 4 2 3 5
//                        j
//                  r
//  ans: 3

// 176ms 18.52% 9.9MB 18.52%
// two pointers
// O(N) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func findLengthOfShortestSubarray(A []int) int {
	n := len(A)
	l, r := 0, n-1
	for l+1 < n && A[l] <= A[l+1] {
		l++
	}
	if l == n-1 {
		return 0
	}
	for r-1 > 0 && A[r-1] <= A[r] {
		r--
	}
	ans := min(n-1-l, r)
	for i, j := 0, r; i <= l && j < n; i++ {
		for j < n && A[i] > A[j] {
			j++
		}
		if j < n {
			ans = min(ans, j-1-i)
		}
	}
	return ans
}
