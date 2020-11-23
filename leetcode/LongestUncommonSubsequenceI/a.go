/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// brain teaser
// O(1) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}
	return max(len(a), len(b))
}

func main() {
	fmt.Println("hello world")
}
