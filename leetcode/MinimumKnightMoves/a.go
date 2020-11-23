/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 568ms, 53.19% 10.6MB, 100.00%
// BFS
// O(8^N) O(8^N)
// N is a distance
func minKnightMoves(ex int, ey int) int {
	if ex == 0 && ey == 0 {
		return 0
	}
	q := [][]int{}
	q = append(q, []int{0, 0})
	dir := [][]int{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}}
	steps := 0
	seen := map[int]map[int]bool{0: map[int]bool{0: true}}
	// BFS loop
	for len(q) > 0 {
		steps++
		n := len(q)
		for i := 0; i < n; i++ {
			t := q[0]
			q = q[1:]
			for _, d := range dir {
				nx := t[0] + d[0]
				ny := t[1] + d[1]
				if nx == ex && ny == ey {
					return steps
				}
				if _, exists := seen[nx]; !exists {
					seen[nx] = map[int]bool{}
				}
				if _, exists := seen[nx][ny]; !exists &&
					(nx*ex >= 0 && ny*ey >= 0 || steps < 3) {
					seen[nx][ny] = true
					q = append(q, []int{nx, ny})
				}
			}
		}
	}
	return -1
}

func main() {
	fmt.Println("hello world")
}
