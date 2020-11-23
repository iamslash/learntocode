/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

// s: first invalid number from left to right
// e: first invalid number from right to left
// e - s + 1 is answer

//    m
//      s
//                  i
// A: 2 6 4 8 10 9 15
//               e
//                  M
//
//        s
//          e
//            i
// A:     2 1
//        M
//          m

// 24ms 100.00% 6.2MB 100.00%
// two pointers
// O(N) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func findUnsortedSubarray(A []int) int {
	n := len(A)
	s, e, minNum, maxNum := -1, -2, math.MaxInt32, math.MinInt32
	for i := 0; i < len(A); i++ {
		maxNum = max(maxNum, A[i])
		minNum = min(minNum, A[n-1-i])
		if A[i] < maxNum {
			e = i
		}
		if A[n-1-i] > minNum {
			s = n - 1 - i
		}
	}
	return e - s + 1
}

func main() {
	fmt.Println("hello world")
}
