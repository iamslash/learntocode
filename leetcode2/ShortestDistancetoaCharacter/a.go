/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// - - - 0 1 0 0 1 2 3 4 0
// l o v e l e e t c o d e
//                 2 2 1 0
//

// 0ms 100.00% 2.4MB 100.00%
// back and forth
// O(N) O(N)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func shortestToChar(s string, c byte) []int {
	cnts := make([]int, len(s))
	last := len(s)
	for i := 0; i < len(s); i++ {
		if s[i] == c {
			last = 0
			cnts[i] = 0
		} else {
			if last >= 0 {
				last++
			}
			cnts[i] = last
		}
	}
	last = len(s)
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == c {
			last = 0
			cnts[i] = 0
		} else {
			if last < len(s) {
				last++
			}
			cnts[i] = min(cnts[i], last)
		}
	}
	return cnts
}

func main() {
	fmt.Println("hello world")
}
