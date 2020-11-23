/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

// _         _
// great rgeat
//

// // 12ms 17.86% 6.1MB 100.00%
// // DFS
// // O(4^N) O(N) N is max(A, B)
// func isScramble(a string, b string) bool {
// 	// base
// 	if len(a) != len(b) {
// 		return false
// 	}
// 	if a == b {
// 		return true
// 	}
// 	ma := make(map[rune]int)
// 	mb := make(map[rune]int)
// 	for _, r := range a {
// 		ma[r]++
// 	}
// 	for _, r := range b {
// 		mb[r]++
// 	}
// 	if !reflect.DeepEqual(ma, mb) {
// 		return false
// 	}

// 	// recursion
// 	n := len(a)
// 	for i := 1; i < n; i++ {
// 		if isScramble(a[:i], b[:i]) && isScramble(a[i:], b[i:]) {
// 			return true
// 		}
// 		if isScramble(a[:i], b[n-i:]) && isScramble(a[i:], b[:n-i]) {
// 			return true
// 		}
// 	}

// 	return false
// }

// 0ms 100.00% 2MB 100.00%
// not use reflect
// O(N^2) O(lgN)
// N is max(A, B)
func EqualCounts(a string, b string) bool {
	n := len(a)
	ma := make([]byte, 256)
	mb := make([]byte, 256)
	for i := 0; i < n; i++ {
		ma[a[i]-'a']++
		mb[b[i]-'a']++
	}
	for i := 0; i < 256; i++ {
		if ma[i] != mb[i] {
			return false
		}
	}
	return true
}

func isScramble(a string, b string) bool {
	// base
	if len(a) != len(b) {
		return false
	}
	if a == b {
		return true
	}
	if !EqualCounts(a, b) {
		return false
	}

	// recursion
	n := len(a)
	for i := 1; i < n; i++ {
		if isScramble(a[:i], b[:i]) && isScramble(a[i:], b[i:]) {
			return true
		}
		if isScramble(a[:i], b[n-i:]) && isScramble(a[i:], b[:n-i]) {
			return true
		}
	}

	return false
}

func main() {
	fmt.Println("hello world")
}
