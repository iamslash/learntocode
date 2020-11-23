/* Copyright (C) 2020 by iamslash */

package main

import "strings"

// If you keep the order  a >= b >= c, There are 2 ways like these.
//
// * "aa"  + ...
// * "aab" + ...

// 0ms 100.00% 2.3MB 31.25%
// greedy algorithm
// O(N) O(N)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func dfs(a, b, c int, ac, bc, cc byte) string {
	// fmt.Printf("a: %d, b: %d, c: %d, ac: %c, bc: %c, cc: %c\n", a, b, c, ac, bc, cc)
	if b > a {
		return dfs(b, a, c, bc, ac, cc)
	}
	if c > b {
		return dfs(a, c, b, ac, cc, bc)
	}
	if b == 0 {
		return strings.Repeat(string(ac), min(2, a))
	}
	usedA := min(2, a)
	usedB := 0
	if a-usedA >= b {
		usedB = 1
	}
	ans := strings.Repeat(string(ac), usedA)
	ans += strings.Repeat(string(bc), usedB)
	return ans + dfs(a-usedA, b-usedB, c, ac, bc, cc)
}
func longestDiverseString(a int, b int, c int) string {
	return dfs(a, b, c, 'a', 'b', 'c')
}
