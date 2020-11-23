/* Copyright (C) 2020 by iamslash */

package main

// i
// 1 0 0 0 1 0 0 1

// 84ms 21.95% 7MB 24.14%
// two pointers
// O(N) O(1)
func kLengthApart(A []int, k int) bool {
	i, j, n := -1, 0, len(A)
	for i < n {
		for j < n && A[j] == 0 {
			j++
		}
		if i >= 0 && j < n && j-i-1 < k {
			return false
		}
		i = j
		j++
	}
	return true
}
