/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// If min(A) + K < max(A) - K, then return max(A) - min(A) - 2 * K
// If min(A) + K >= max(A) - K, then return 0

// 12ms 97.83% 5.9MB 100.00%
// linear traversal
// O(N) O(1)
func smallestRangeI(A []int, K int) int {
	minA, maxA := A[0], A[0]
	for _, a := range A {
		if minA > a {
			minA = a
		}
		if maxA < a {
			maxA = a
		}
	}
	ans := maxA - minA - K - K
	if ans < 0 {
		return 0
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
