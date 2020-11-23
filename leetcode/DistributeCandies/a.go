/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 164ms 95.24% 6.9MB 100.00%
// hash
// O(N) O(N)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func distributeCandies(candies []int) int {
	half := len(candies) / 2
	ust := make(map[int]bool)
	for _, id := range candies {
		ust[id] = true
	}
	return min(half, len(ust))
}

func main() {
	fmt.Println("hello world")
}
