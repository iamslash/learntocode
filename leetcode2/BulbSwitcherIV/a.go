/* Copyright (C) 2020 by iamslash */

package main

//                   i
//     s:   1 0 1 1 1
// state: 0 1 0 1
//   ans: 0 1 2 3

// 4ms 90.74% 4.9MB 100.00%
// linear traversal
// O(N) O(1)
func minFlips(s string) int {
	state, ans := byte('0'), 0
	for i := 0; i < len(s); i++ {
		if state != s[i] {
			state = s[i]
			ans++
		}
	}
	return ans
}
