/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 90.70% 4.2MB 100.00%
// DFS
// O(HW) O(HW)
func dfs(image [][]int, y int, x int, color int, newColor int) {
	// base
	if y < 0 || y >= len(image) || x < 0 || x >= len(image[0]) || image[y][x] != color {
		return
	}
	// recursion
	image[y][x] = newColor
	dfs(image, y-1, x, color, newColor)
	dfs(image, y+1, x, color, newColor)
	dfs(image, y, x-1, color, newColor)
	dfs(image, y, x+1, color, newColor)
}
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	if image[sr][sc] == newColor {
		return image
	}
	dfs(image, sr, sc, image[sr][sc], newColor)
	return image
}

func main() {
	fmt.Println("hello world")
}
