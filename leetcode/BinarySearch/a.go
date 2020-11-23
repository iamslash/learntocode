/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 36ms 65.70% 6.5MB 50.00%
// binary search
// O(N) O(1)
func search(A []int, tgt int) int {
	lo, mi, hi := 0, 0, len(A)-1
	for lo < hi {
		mi = lo + (hi-lo)/2
		if A[mi] < tgt {
			lo = mi + 1
		} else {
			hi = mi
		}
	}
	if A[lo] == tgt {
		return lo
	}
	return -1
}

func main() {
	fmt.Println("hello world")
}
