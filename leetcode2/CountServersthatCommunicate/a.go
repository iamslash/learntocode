/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 56ms 72.34% 6.5MB 100.00%
// array
// O(HW) O(max(H, W))
func countServers(G [][]int) int {
	h, w, cnt := len(G), len(G[0]), 0
	rows := make([]int, h)
	cols := make([]int, w)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if G[y][x] > 0 {
				rows[y]++
				cols[x]++
			}
		}
	}
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if G[y][x] > 0 && (rows[y] > 1 || cols[x] > 1) {
				cnt++
			}
		}
	}
	return cnt
}

func main() {
	fmt.Println("hello world")
}
