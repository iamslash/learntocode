/* Copyright (C) 2020 by iamslash */

package main

//     3
//    11
//
//     0
//    10
//   100
//   110
//  1000
//  1010
//  1100
//  1110

// 0ms 100.00% 1.9MB 100.00%
// bit manipulation
// O(N) O(1)
func xorOperation(n int, start int) int {
	xor := 0
	for i := 0; i < n; i++ {
		xor ^= start + 2*i
	}
	return xor
}
