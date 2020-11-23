/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 28ms 56.58% 6.1MB 100.00%
// O(1) O(1)
func isPowerOfThree(n int) bool {
	// 3^19 = 1162261467
	// 3^20 > math.maxInt32
	return n > 0 && 1162261467%n == 0
}

func main() {
	fmt.Println("hello world")
}
