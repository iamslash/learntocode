/* Copyright (C) 2020 by iamslash */

package main

//
// A: 1 5
//    0 5
//    0 4
//    0 2
//    0 1
//    0 0

// A: 2 2
//    1 1
//    0 1
//    0 0

//    i
// A: 4 2 5
//    4 2 4
//    2 1 2
//    2 0 2
//    1 0 1
//    0 0 1
//    0 0 0
//

//           i
//      A: 4 2 5
//      a:   1
//    ans: 1 2 3
// maxLen: 1 1 3
//   bits: 3 2 3
//

// 40ms 95.56% 6.6MB 68.89%
// greedy algorithm
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func minOperations(A []int) int {
	ans, maxLen := 0, 1
	for _, a := range A {
		bits := 0
		for a > 0 {
			if a&1 > 0 {
				ans++
			}
			bits++
			a >>= 1
		}
		maxLen = max(maxLen, bits)
	}
	return ans + maxLen - 1
}
