/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"regexp"
	"strings"
)

// 4ms 30.77% 3MB 100.00%
// hash map, regex
// O(N) O(N)
func mostCommonWord(s string, B []string) string {
	s = strings.ToLower(s)
	reg, _ := regexp.Compile("[^a-zA-Z ]+")
	s = reg.ReplaceAllString(s, " ")
	words := strings.Fields(s)

	banMap := make(map[string]bool)
	for _, ban := range B {
		banMap[ban] = true
	}
	cntMap := make(map[string]int)
	maxCnt := 0
	maxStr := ""
	for _, word := range words {
		if !banMap[word] {
			cntMap[word]++
			if cntMap[word] > maxCnt {
				maxCnt = cntMap[word]
				maxStr = word
			}
		}
	}
	return maxStr
}

func main() {
	fmt.Println("hello world")
}
