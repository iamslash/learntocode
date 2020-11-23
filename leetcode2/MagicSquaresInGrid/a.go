/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.2MB 100.00%
// brute force
// O(N) O(1)
func check(G []int) bool {
	// check unique
	seen := make(map[int]int, 9)
	for _, v := range G {
		if v < 1 || v > 9 {
			return false
		}
		seen[v]++
		if seen[v] > 1 {
			return false
		}
	}
	// check sum
	return (G[0]+G[1]+G[2] == 15 &&
		G[3]+G[4]+G[5] == 15 &&
		G[6]+G[7]+G[8] == 15 &&
		G[0]+G[3]+G[6] == 15 &&
		G[1]+G[4]+G[7] == 15 &&
		G[2]+G[5]+G[8] == 15 &&
		G[0]+G[4]+G[8] == 15 &&
		G[2]+G[4]+G[6] == 15)
}
func numMagicSquaresInside(G [][]int) int {
	ans := 0
	for i := 1; i <= len(G)-2; i++ {
		for j := 1; j <= len(G[0])-2; j++ {
			if G[i][j] != 5 {
				continue
			}
			if check([]int{
				G[i-1][j-1], G[i-1][j], G[i-1][j+1],
				G[i][j-1], G[i][j], G[i][j+1],
				G[i+1][j-1], G[i+1][j], G[i+1][j+1],
			}) {
				ans++
			}
		}
	}

	return ans
}

func main() {
	fmt.Println("hello world")
}
