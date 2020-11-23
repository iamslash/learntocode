/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
)

// 4ms 89.33% 2.8MB 100.00%
// array
// O(NlgN) O(1)
func flipAndInvertImage(A [][]int) [][]int {
	for _, line := range A {
		for i, j := 0, len(line)-1; i < j; i, j = i+1, j-1 {
			line[i], line[j] = line[j], line[i]
		}
		for i := 0; i < len(line); i++ {
			line[i] ^= 1
		}
	}
	return A
}

func main() {
	fmt.Println("hello world")
}
