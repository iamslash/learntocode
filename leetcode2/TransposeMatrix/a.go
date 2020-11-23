/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 78.95% 5.9MB 100.00%
// brute force
// O(HW) O(1)
func transpose(A [][]int) [][]int {
	h, w := len(A), len(A[0])
	M := make([][]int, w)
	for i := 0; i < w; i++ {
		M[i] = make([]int, h)
	}
	fmt.Println(M)
	for y := 0; y < w; y++ {
		for x := 0; x < h; x++ {
			// fmt.Printf("y: %d, x: %d\n", y, x)
			M[y][x] = A[x][y]
		}
	}
	return M
}

func main() {
	fmt.Println("hello world")
}
