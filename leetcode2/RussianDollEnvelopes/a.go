/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"math"
	"sort"
)

// E: [[5,4],[6,4],[6,7],[2,3]]
//                          i
// E: [[2,3],[5,4],[6,4],[6,7]]
//                    j
// C: 1 2 3 3

// Wrong answer
// dynamic programming
// O(N^2) O(N)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSlice(A []int) int {
	r := math.MinInt32
	for _, a := range A {
		if r < a {
			r = a
		}
	}
	return r
}
func maxEnvelopes(E [][]int) int {
	if len(E) == 0 {
		return 0
	}
	sort.Slice(E, func(i, j int) bool {
		if E[i][0] == E[j][0] {
			return E[i][1] < E[j][1]
		}
		return E[i][0] < E[j][0]
	})
	C := make([]int, len(E))
	for i := 0; i < len(C); i++ {
		C[i] = 1
	}
	for i := 0; i < len(E); i++ {
		for j := 0; j < i; j++ {
			if E[j][0] < E[i][0] && E[j][1] < E[i][1] {
				C[i] = max(C[i], C[j]+1)
			}
		}
	}
	return maxSlice(C)
}

func main() {
	fmt.Println("hello world")
}
