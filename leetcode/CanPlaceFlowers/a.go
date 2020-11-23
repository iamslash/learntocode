/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// i
//   0 0 1 0 1
//       j

// 1 0 0 0 0 0 0 0 1

// 16ms 89.86% 5.9MB 100.00%
// sliding window
// O(N) O(1)
func canPlaceFlowers(FB []int, n int) bool {
	i, j, cnt := -2, 0, 0
	for j = 0; j < len(FB); j++ {
		for j < len(FB) && FB[j] == 0 {
			j++
		}
		if j == len(FB) {
			j = len(FB) + 1
		}
		zCnt := j - i - 1
		if i < 0 || j >= len(FB) || zCnt >= 3 {
			cnt += (zCnt - 1) / 2
		}
		i = j
	}
	return cnt >= n
}

func main() {
	A := []int{1, 0, 0, 0, 1, 0, 0}
	n := 1
	fmt.Println(canPlaceFlowers(A, n))
}
