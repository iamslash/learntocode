/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 56ms 88.46% 6.7MB 100.00%
// hash
// O(N) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func findLHS(A []int) int {
	cnts := make(map[int]int)
	for _, num := range A {
		cnts[num]++
	}
	lhs := 0
	for iNum, iCnt := range cnts {
		if jCnt, ok := cnts[iNum-1]; ok {
			lhs = max(lhs, iCnt+jCnt)
		}
	}
	return lhs
}

func main() {
	fmt.Println("hello world")
}
