/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// xz = sum(max value for every col)
// yz = sum(max value for every row)
// xy = sum(1 for every v > 0)

// 4ms 100.00% 3.7MB 100.00%
// O(N^2) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func projectionArea(G [][]int) int {
	ans, n, x, y := 0, len(G), 0, 0
	for i := 0; i < n; i++ {
		x, y = 0, 0
		for j := 0; j < n; j++ {
			x = max(x, G[i][j])
			y = max(y, G[j][i])
			if G[i][j] > 0 {
				ans++
			}
		}
		ans += x + y
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
