/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 00111
// 01 0011

// 0001111
// 01 0011 000111

// 00110011
// 2 2 2 2
// i
//

//         i
// 00110011
//
// cur: 2
// prv: 2
// rst: 6

// 8ms 85.71% 5.9MB 100.00%
// string
// O(N) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func countBinarySubstrings(s string) int {
	cur, prv, rst := 1, 0, 0
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cur++
		} else {
			rst += min(prv, cur)
			prv = cur
			cur = 1
		}
	}
	return rst + min(cur, prv)
}

func main() {
	fmt.Println("hello world")
}
