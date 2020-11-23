/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 100ms 9.52% 7.3MB 100.00%
// brute force
// O(C) O(O)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func robotSim(C []int, O [][]int) int {
	obstacleMap := make(map[string]bool)
	for _, pos := range O {
		obstacleMap[fmt.Sprintf("%d %d", pos[0], pos[1])] = true
	}
	ans, dir, x, y := 0, 0, 0, 0
	delta := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	for i := range C {
		if C[i] == -2 {
			dir = (dir + 3) % 4
		} else if C[i] == -1 {
			dir = (dir + 1) % 4
		} else {
			for j := 0; j < C[i]; j++ {
				nx := x + delta[dir][0]
				ny := y + delta[dir][1]
				pos := fmt.Sprintf("%d %d", nx, ny)
				if _, ok := obstacleMap[pos]; ok == true {
					break
				}
				x = nx
				y = ny
			}
			ans = max(ans, x*x+y*y)
		}
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
