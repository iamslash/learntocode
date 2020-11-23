/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 68ms 96.30% 9.1MB 100.00%
// binary search
// O(NlgN) O(1)
func smallestCommonElement(M [][]int) int {
	// edges
	if len(M) == 1 {
		return M[0][0]
	}
	for _, v := range M[0] {
		found := true
		for i := 1; i < len(M); i++ {
			if j := sort.SearchInts(M[i], v); j == len(M[i]) || M[i][j] != v {
				found = false
				break
			}
		}
		if found {
			return v
		}
	}
	return -1
}

func main() {
	M := [][]int{{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}}
	fmt.Println(smallestCommonElement(M))
	// A := []int{2, 3, 5, 6}
	// fmt.Println(sort.SearchInts(A, 1))
	// fmt.Println(sort.SearchInts(A, 3))
	// fmt.Println(sort.SearchInts(A, 4))
	// fmt.Println(sort.SearchInts(A, 7))
}
