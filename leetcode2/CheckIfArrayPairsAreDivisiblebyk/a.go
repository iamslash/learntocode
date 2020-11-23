/* Copyright (C) 2020 by iamslash */

package main

// 132ms 68.64% 10.1MB 32.20%
// hash map
// O(N) O(N)
func canArrange(A []int, k int) bool {
	n, cntMap := len(A), make(map[int]int)
	for i := 0; i < n; i++ {
		rem := (A[i]%k + k) % k
		cntMap[rem]++
	}
	if cntMap[0]&1 > 0 {
		return false
	}
	for i := 1; i <= n/2; i++ {
		if cntMap[i]&1 > 0 {
			return false
		}
	}
	return true
}
