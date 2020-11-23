/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
func isRectangleOverlap(A []int, B []int) bool {
	return A[0] < B[2] && B[0] < A[2] &&
		A[1] < B[3] && B[1] < A[3]
}

func main() {
	fmt.Println("hello world")
}
