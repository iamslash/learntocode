/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
// hamming weight
// O(1) O(1)
func hammingWeight(n uint32) int {
	r := 0

	for n > 0 {
		r++
		n &= (n - 1)
	}

	return r
}

func main() {
	fmt.Println("hello world")
}
