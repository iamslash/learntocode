/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 12ms 93.10% 5.9MB 100.00%
// hash
// O(NlgN) O(N)
func longestWord(words []string) string {
	sort.Strings(words)
	ump := make(map[string]bool)
	rslt := ""
	for _, word := range words {
		if _, ok := ump[word[:len(word)-1]]; ok == true || len(word) == 1 {
			if len(word) > len(rslt) {
				rslt = word
			}
			ump[word] = true
		}
	}
	return rslt
}

func main() {
	fmt.Println("hello world")
}
