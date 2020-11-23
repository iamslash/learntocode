/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 4ms 87.50% 6.1MB 100.00%
// hashmap
// O(N) O(N)
func getCharCnt(L string) []int {
	charCnt := make([]int, 26)
	for i := 0; i < len(L); i++ {
		if L[i] >= 'a' && L[i] <= 'z' {
			charCnt[L[i]-'a']++
		} else if L[i] >= 'A' && L[i] <= 'Z' {
			charCnt[L[i]-'A']++
		}
	}
	return charCnt
}
func shortestCompletingWord(L string, W []string) string {
	licenseCharCnt := getCharCnt(L)
	minIdx, j := -1, 0
	for i, word := range W {
		wordCharCnt := getCharCnt(word)
		for j = 0; j < 26; j++ {
			if licenseCharCnt[j] > wordCharCnt[j] {
				break
			}
		}
		if j < 26 {
			continue
		}
		if minIdx < 0 || len(W[minIdx]) > len(word) {
			minIdx = i
		}
	}
	return W[minIdx]
}

func main() {
	fmt.Println("hello world")
}
