/* Copyright (C) 2020 by iamslash */

package main

import "strings"

// 0ms 100.00% 1.9MB 70.92%
// array
// O(N) O(N)
func isPrefixOfWord(sentence string, searchWord string) int {
	S := strings.Split(sentence, " ")
	for i := 0; i < len(S); i++ {
		if strings.HasPrefix(S[i], searchWord) {
			return i + 1
		}
	}
	return -1
}
