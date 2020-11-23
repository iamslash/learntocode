/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 83.87% 4.8MB 100.00%
// linear traversal
// O(N) O(1)
func peakIndexInMountainArray(A []int) int {
	maxEl := 0
	for _, a := range A {
		if maxEl < a {
			maxEl = a
		}
	}
	return maxEl
}

func main() {
	fmt.Println("hello world")
}
