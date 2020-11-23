/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

// // 12ms 51.85% 8.6MB 50.00
// // string
// // O(N) O(1)
// func repeatedStringMatch(A string, B string) int {
// 	cnt := 1
// 	s := A
// 	for len(s) < len(B) {
// 		s += A
// 		cnt++
// 	}
// 	if strings.Contains(s, B) {
// 		return cnt
// 	}
// 	s += A
// 	cnt++
// 	if strings.Contains(s, B) {
// 		return cnt
// 	}
// 	return -1
// }

// abcdabcdabcd
// cdabcdab
// aaacaaac
//  aac
// aaa
// aa

// 24ms 22.22% 8.5MB 50.00%
// string
// O(N) O(1)
func repeatedStringMatch(A string, B string) int {
	cnt := 1
	s := A
	for len(s) < len(B) {
		s += A
		cnt++
	}
	s += A
	cnt++
	for i := 0; i <= len(s)-len(B); i++ {
		if s[i:i+len(B)] == B {
			if i+len(B) <= len(s)-len(A) {
				cnt--
			}
			return cnt
		}
	}
	return -1
}

func main() {
	A := "a"
	B := "aa"
	fmt.Println(repeatedStringMatch(A, B))
}
