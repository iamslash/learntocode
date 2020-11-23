/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 1 0 1
// 0 1 0

// colsum[i] == 0 or colsum[i] == 2
// colsum[i] == 1

// 80ms 87.50% 9.8MB 100.00%
// greedy
// O(N) O(N)
func reconstructMatrix(u int, l int, C []int) [][]int {
	mat := make([][]int, 2)
	mat[0] = make([]int, len(C))
	mat[1] = make([]int, len(C))
	x := 0
	for x < len(C) {
		if C[x] == 2 || (C[x] == 1 && l < u) {
			mat[0][x] = 1
		}
		if C[x] == 2 || (C[x] == 1 && mat[0][x] != 1) {
			mat[1][x] = 1
		}
		u -= mat[0][x]
		l -= mat[1][x]
		x++
	}
	if u == 0 && l == 0 {
		return mat
	}
	return [][]int{}
}

func main() {
	fmt.Println("hello world")
}
