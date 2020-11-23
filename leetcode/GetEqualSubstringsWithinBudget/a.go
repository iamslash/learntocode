/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// slide window size cannot be lesser than before.
//
//           i
//       s: abcd
//       t: bcdf
//              j
// maxCost: -1

//           i
//       s: abcd
//       t: cbdf
//              j
// maxCost: 0

// 0ms 100.00% 3.1MB 100.00%
// two pointers
// O(N) O(N)
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func equalSubstring(s string, t string, maxCost int) int {
	i, j := 0, 0
	for j < len(s) {
		maxCost -= abs(int(s[j]) - int(t[j]))
		j++
		if maxCost < 0 {
			maxCost += abs(int(s[i]) - int(t[i]))
			i++
		}
	}
	return j - i
}

func main() {
	fmt.Println("hello world")
}
