/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 4ms 92.86% 4.3MB 100.00%
// hashmap
// O(N) O(1)
func canConstruct(R string, M string) bool {
	mapR := make([]int, 26)
	for _, rune := range M {
		mapR[rune-'a']++
	}
	for _, rune := range R {
		if mapR[rune-'a'] == 0 {
			return false
		}
		mapR[rune-'a']--
	}
	return true
}

func main() {
	fmt.Println(canConstruct("aa", "aab"))
}
