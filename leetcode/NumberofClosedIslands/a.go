/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 100.00% 4.9MB 100.00%
// DFS
// O(HW) O(lg4HW)
func dfs(G [][]int, y, x int) int {
	// base
	if y < 0 || y >= len(G) || x < 0 || x >= len(G[0]) || G[y][x] == 1 {
		return 0
	}
	G[y][x] = 1
	// recursion
	cnt := 1
	cnt += dfs(G, y-1, x) + dfs(G, y+1, x)
	cnt += dfs(G, y, x-1) + dfs(G, y, x+1)
	return cnt
}
func closedIsland(G [][]int) int {
	// flood 1 out boundary
	for y := 0; y < len(G); y++ {
		for x := 0; x < len(G[0]); x++ {
			if y*x == 0 || y == len(G)-1 || x == len(G[0])-1 {
				dfs(G, y, x)
			}
		}
	}
	// count islands
	cnt := 0
	for y := 1; y < len(G)-1; y++ {
		for x := 1; x < len(G[0])-1; x++ {
			if dfs(G, y, x) > 0 {
				cnt++
			}
		}
	}
	return cnt
}

func main() {
	fmt.Println("hello world")
}
