/* Copyright (C) 2020 by iamslash */

package main

import "math"

// s1: 0                  2^1-1
// s2: 011                2^2-1
//       k
// s3: 0111001            2^3-1
//         k
// s4: 011100110110001    2^4-1
//             k

// recursion
// O(N) O(N)
func findKthBit(n int, k int) byte {
	// base
	if n == 1 {
		return '0'
	}
	// recursion
	len := int(math.Pow(2, float64(n))) - 1
	prevLen := int(math.Pow(2, float64(n-1))) - 1
	if k-1 == prevLen {
		return '1'
	}
	if k-1 < prevLen {
		return findKthBit(n-1, k)
	}
	bit := findKthBit(n-1, len-k+1)
	if bit == '0' {
		return '1'
	}
	return '0'
}
