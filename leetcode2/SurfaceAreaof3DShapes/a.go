/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4MS 100.00% 3.7MB 100.00%
// math
// O(HW) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func surfaceArea(G [][]int) int {
	h, w, sum := len(G), len(G[0]), 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if G[y][x] == 0 {
				continue
			}
			sum += 4*G[y][x] + 2
			if y > 0 {
				sum -= min(G[y][x], G[y-1][x])
			}
			if y < h-1 {
				sum -= min(G[y][x], G[y+1][x])
			}
			if x > 0 {
				sum -= min(G[y][x], G[y][x-1])
			}
			if x < w-1 {
				sum -= min(G[y][x], G[y][x+1])
			}
		}
	}
	return sum
}

func main() {
	fmt.Println("hello world")
}
