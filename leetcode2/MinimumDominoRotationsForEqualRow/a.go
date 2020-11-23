/* Copyright (C) 2020 by iamslash */

package main

//    i
// A: 2 1 2 4 2 2
// B: 5 2 6 2 3 2
//
//       0 1 2 3 4 5 6
// cntA: 0 1 4   1
// cntB: 0   3 1   1 1
// same: 0   1

// 200ms 15.38% 7.7MB 5.13%
// hash map
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func minDominoRotations(A []int, B []int) int {
	n := len(A)
	cntA := make([]int, 6)
	cntB := make([]int, 6)
	same := make([]int, 6)
	for i := 0; i < n; i++ {
		cntA[A[i]-1]++
		cntB[B[i]-1]++
		if A[i] == B[i] {
			same[A[i]-1]++
		}
	}
	for i := 0; i < 6; i++ {
		if cntA[i]+cntB[i]-same[i] == n {
			return n - max(cntA[i], cntB[i])
		}
	}
	return -1
}
