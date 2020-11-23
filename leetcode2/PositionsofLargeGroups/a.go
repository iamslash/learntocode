/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// i
// a b b x x x x z z y
//   j

//       i
// a b c d d d e e e e a a b b b c d
//             j

// 0ms 100%
// linear traversal
// O(N) O(N)
func largeGroupPositions(s string) [][]int {
	ans := [][]int{}
	for i, j := 0, 0; i < len(s); i++ {
		j = i
		for j < len(s) && s[i] == s[j] {
			j++
		}
		diff := j - i
		if diff >= 3 {
			ans = append(ans, []int{i, j - 1})
		}
		i = j - 1
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
