/* Copyright (C) 2020 by iamslash */

package main

//  4  3  2 -1
//  3  2  1 -1
//  1  1 -1 -2
// -1 -1 -2 -3

// 12ms 97.63% 6MB 87.08%
// brute force
// O(HW) O(1)
func countNegatives(G [][]int) int {
	ans, h, w := 0, len(G), len(G[0])
	for y := 0; y < h; y++ {
		for x := w - 1; x >= 0; x-- {
			if G[y][x] >= 0 {
				break
			}
			ans++
		}
	}
	return ans
}
