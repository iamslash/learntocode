/* Copyright (C) 2020 by iamslash */

package main

// n : 2
//
// P1 D1 P2 D2
//    P2 D1 D2
//    P2 D2 D1
// P2 P1 D1 D2
//    P1 D2 D1
//    D2 P1 D1

// permutation
// O(N) O(1)
func countOrders(n int) int {
	var mod int = 1000000007
	var ans int = 1
	for n > 0 {
		ans *= n * (2*n - 1)
		ans %= mod
		n--
	}
	return ans
}
