/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 1 2 2 3 1

//      A: 1 2 2 3 1 4 2
//                   i
//   cnts: 1 2 3 4
//         2 2 1 1
//  first: 1 2 3 4
//         0 1 3 5
// degree: 2
// minCnt: 2

// 28ms 96.08% 6.4MB 100.00%
// hash map
// O(N) O(N)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func findShortestSubArray(A []int) int {
	cnts, first := make(map[int]int), make(map[int]int)
	minCnt, degree := 0, 0
	for i, a := range A {
		if _, ok := first[a]; ok == false {
			first[a] = i
		}
		if cnts[a]++; cnts[a] > degree {
			degree = cnts[a]
			minCnt = i - first[a] + 1
		} else if cnts[a] == degree {
			minCnt = min(minCnt, i-first[a]+1)
		}
	}
	return minCnt
}

func main() {
	fmt.Println("hello world")
}
