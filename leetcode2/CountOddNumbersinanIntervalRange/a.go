/* Copyright (C) 2020 by iamslash */

package main

// 2 3: 1
// 2 4: 1

// 3 5: 2
// 3 6: 2
// 2 5: 2
// 2 6: 2

// math
// 0ms 100.00% 2MB 100.00%
func countOdds(l int, h int) int {
	ans := 0
	if l&1 > 0 && h&1 > 0 {
		ans++
	}
	ans += (h - l + 1) / 2
	return ans
}
