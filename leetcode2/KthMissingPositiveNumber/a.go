/* Copyright (C) 2020 by iamslash */

package main

// k: 5
//    2
//          i
// A: 2 3 4 7 11
// n: 1 2 3 4

// 0ms 100.00% 2.9MB 100.00%
// linear traversal
// O(N) O(1)
func findKthPositive(A []int, k int) int {
	for i, n := 0, 1; n <= 1000; n++ {
		if i < len(A) && A[i] == n {
			i++
		} else {
			k--
			if k == 0 {
				return n
			}
		}
	}
	return 1000 + k
}
