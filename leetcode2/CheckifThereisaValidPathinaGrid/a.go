/* Copyright (C) 2020 by iamslash */

package main

// 176ms 33.33% 24.6MB 22.22%
// DFS
// O(2^N) O(N^2)
func dfs(y, x, h, w int, seen [][]bool, G [][]int, dir byte) bool {
	// base
	if y < 0 || y >= h || x < 0 || x >= w || seen[y][x] {
		return false
	}
	if dir == 'l' && (G[y][x] == 2 || G[y][x] == 3 || G[y][x] == 5) {
		return false
	} else if dir == 'd' && (G[y][x] == 1 || G[y][x] == 3 || G[y][x] == 4) {
		return false
	} else if dir == 'r' && (G[y][x] == 2 || G[y][x] == 4 || G[y][x] == 6) {
		return false
	} else if dir == 'u' && (G[y][x] == 1 || G[y][x] == 5 || G[y][x] == 6) {
		return false
	} else if y == h-1 && x == w-1 {
		return true
	}
	seen[y][x] = true
	// recursion
	if G[y][x] == 1 {
		return dfs(y, x-1, h, w, seen, G, 'l') || dfs(y, x+1, h, w, seen, G, 'r')
	} else if G[y][x] == 2 {
		return dfs(y-1, x, h, w, seen, G, 'u') || dfs(y+1, x, h, w, seen, G, 'd')
	} else if G[y][x] == 3 {
		return dfs(y, x-1, h, w, seen, G, 'l') || dfs(y+1, x, h, w, seen, G, 'd')
	} else if G[y][x] == 4 {
		return dfs(y, x+1, h, w, seen, G, 'r') || dfs(y+1, x, h, w, seen, G, 'd')
	} else if G[y][x] == 5 {
		return dfs(y, x-1, h, w, seen, G, 'l') || dfs(y-1, x, h, w, seen, G, 'u')
	} else if G[y][x] == 6 {
		return dfs(y, x+1, h, w, seen, G, 'r') || dfs(y-1, x, h, w, seen, G, 'u')
	}
	return false
}
func hasValidPath(G [][]int) bool {
	h, w := len(G), len(G[0])
	seen := make([][]bool, h)
	for y := 0; y < h; y++ {
		seen[y] = make([]bool, w)
	}
	return dfs(0, 0, h, w, seen, G, ' ')
}
