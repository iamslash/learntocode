/* Copyright (C) 2020 by iamslash */

package main

//    i j
// A: 4 5 8
//           k
// B: 1 8 9 10

//
// A:  1 2 3 4
//     k
// B: -4 -3 6 10 20 30
// d: 3

// 4ms 98.36% 3.8MB 100.00%
// brute force
// O(N^2) O(1)
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func findTheDistanceValue(A []int, B []int, d int) int {
	ans := 0
	for _, a := range A {
		found := true
		for _, b := range B {
			if abs(a-b) <= d {
				found = false
				break
			}
		}
		if found {
			ans++
		}
	}
	return ans
}
