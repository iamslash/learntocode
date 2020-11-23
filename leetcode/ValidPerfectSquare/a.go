/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00$ 2MB 50.00%
// binary search
// O(lgN) O(1)
func isPerfectSquare(n int) bool {
	l, m, h := 0, 0, n
	for l < h {
		m = (l + h) / 2
		if m*m < n {
			l = m + 1
		} else {
			h = m
		}
	}
	return l*l == n
}

func main() {
	fmt.Println(isPerfectSquare(49))
	fmt.Println(isPerfectSquare(48))
}
