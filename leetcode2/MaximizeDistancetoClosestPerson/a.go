/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// i       j
// 1 0 0 0 1 0 1

// 12ms 82.61% 5.4MB 100.00%
// two pointers
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxDistToClosest(S []int) int {
	last, maxDist := -1, 0
	for i := 0; i < len(S); i++ {
		if S[i] == 1 {
			if last < 0 {
				maxDist = i
			} else {
				maxDist = max(maxDist, (i-last)/2)
			}
			last = i
		}
	}
	maxDist = max(maxDist, len(S)-last-1)
	return maxDist
}

func main() {
	s := []int{1, 0, 0, 0, 1, 0, 1}
	fmt.Println(maxDistToClosest(s))
}
