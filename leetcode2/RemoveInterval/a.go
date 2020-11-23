/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// edge cases
// [[0,5]]
// [2,3]

// 68ms 77.78%
// greedy algorithm
// O(N) O(N)
func removeInterval(intervals [][]int, R []int) [][]int {
	ans := [][]int{}
	for _, i := range intervals {
		if i[1] <= R[0] || R[1] <= i[0] {
			ans = append(ans, i)
			continue
		}
		if i[0] < R[0] && R[0] < i[1] {
			ans = append(ans, []int{i[0], R[0]})
		}
		if i[0] < R[1] && R[1] < i[1] {
			ans = append(ans, []int{R[1], i[1]})
		}
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
