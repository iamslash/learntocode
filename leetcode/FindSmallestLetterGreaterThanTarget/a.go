/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//    l
// A: c f j
//      r
//    m

// 0ms 100.00% 2.9MB 100.00%
// binary search
// O(lgN) O(1)
func nextGreatestLetter(L []byte, T byte) byte {
	lo, mi, hi := 0, 0, len(L)-1
	for lo < hi {
		mi = lo + (hi-lo)/2
		if L[mi] <= T {
			lo = mi + 1
		} else {
			hi = mi
		}
	}
	if L[lo] > T {
		return L[lo]
	}
	return L[0]
}

func main() {
	fmt.Println("hello world")
}
