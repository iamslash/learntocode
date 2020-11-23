/* Copyright (C) 2020 by iamslash */

package main

// 96ms 67.65% 10MB 49.02%
// sliding window, hash map
// O(N) O(K)
func hasAllCodes(s string, k int) bool {
	n := len(s)
	bmSet := make(map[string]bool)
	for i := 0; i <= n-k; i++ {
		bmSet[s[i:i+k]] = true
	}
	cnt := 1 << k
	return len(bmSet) == cnt
}
