/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"strings"
)

// 0ms 100.00% 6MB 100.00%
// linear traversal
// O(N) O(N)
func vowel(c byte) bool {
	return strings.Contains("aeiouAEIOU", string(c))
}
func toGoatLatin(s string) string {
	words := strings.Split(s, " ")
	ans := ""
	for i, w := range words {
		t := ""
		if vowel(w[0]) {
			t = w
		} else {
			t = w[1:] + string(w[0])
		}
		ans = ans + t + "ma"
		for j := 0; j <= i; j++ {
			ans = ans + "a"
		}
		ans += " "
	}
	return ans[0 : len(ans)-1]
}

func main() {
	fmt.Println("hello world")
}
