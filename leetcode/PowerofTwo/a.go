/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.2MB 100.00%
// hamming weight
// O(1) O(1)
func isPowerOfTwo(n int) bool {
	if n == 0 {
		return false
	}
	return (n & (n - 1)) == 0
}

func main() {
	fmt.Println(isPowerOfTwo(1))
	fmt.Println(isPowerOfTwo(16))
	fmt.Println(isPowerOfTwo(218))
}
