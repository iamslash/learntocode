/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"unicode"
)

// 0ms 100.00% 2MB 66.67%
// hash
// O(N) O(N)
func sameRow(s string) bool {
	ump := map[rune]int{
		'q': 1, 'w': 1, 'e': 1, 'r': 1, 't': 1, 'y': 1, 'u': 1, 'i': 1, 'o': 1, 'p': 1,
		'a': 2, 's': 2, 'd': 2, 'f': 2, 'g': 2, 'h': 2, 'j': 2, 'k': 2, 'l': 2,
		'z': 3, 'x': 3, 'c': 3, 'v': 3, 'b': 3, 'n': 3, 'm': 3,
	}
	for i := 1; i < len(s); i++ {
		if ump[unicode.ToLower(rune(s[i-1]))] !=
			ump[unicode.ToLower(rune(s[i]))] {
			return false
		}
	}
	return true
}
func findWords(words []string) []string {
	rst := []string{}
	for _, w := range words {
		if sameRow(w) {
			rst = append(rst, w)
		}
	}
	return rst
}

func main() {
	fmt.Println("hello world")
}
