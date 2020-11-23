/* Copyright (C) 2020 by iamslash */

package main

//            i
//   s: 1 1 0 1
//   c: 0
// ans: 0

// 0ms 100.00% 2MB 100.00%
// linear traversal
// O(N) O(1)
func numSteps(s string) int {
	ans, c, n := 0, 0, len(s)
	for i := n - 1; i > 0; i-- {
		if int(s[i]-'0')+c == 1 {
			c = 1
			ans++
		}
		ans++
	}
	return ans
}
