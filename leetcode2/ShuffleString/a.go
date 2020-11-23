/* Copyright (C) 2020 by iamslash */

package main

// I: 4 5 6 7 0 2 1 3
//
// s: c o d e l e e t
//

// 0ms 100.00% 3.3MB 100.00%
// array
// O(N) O(N)
func restoreString(s string, I []int) string {
	n := len(s)
	ans := make([]byte, n)
	for i := 0; i < n; i++ {
		ans[I[i]] = s[i]
	}
	return string(ans)
}
