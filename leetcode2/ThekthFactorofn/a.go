/* Copyright (C) 2020 by iamslash */

package main

// 0ms 100.00% 2.1MB 100.00%
// math
// O(N) O(1)
func kthFactor(n int, k int) int {
	for i := 1; i <= n && k > 0; i++ {
		if n%i == 0 {
			k--
			if k == 0 {
				return i
			}
		}
	}
	return -1
}
