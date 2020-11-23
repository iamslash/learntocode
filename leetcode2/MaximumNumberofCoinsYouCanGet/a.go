/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// 9 8 7 6 5 4 3 2 1
// . .             .
//     . .       .
//         . . .

// // 168ms 57.60% 7.8MB 67.20%
// // sort
// // O(NlgN) O(1)
// func maxCoins(P []int) int {
// 	sort.Sort(sort.Reverse(sort.IntSlice(P)))
// 	n, ans := len(P), 0
// 	for i, j := 0, 1; i < n/3; i, j = i+1, j+2 {
// 		ans += P[j]
// 	}
// 	return ans
// }

// 148ms 65.60% 7.9MB 62.40%
// sort
// O(NlgN) O(1)
func maxCoins(P []int) int {
	sort.Ints(P)
	n, ans := len(P), 0
	for i := n / 3; i < n; i += 2 {
		ans += P[i]
	}
	return ans
}
