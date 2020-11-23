/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"strings"
)

// 4ms 83.61% 4.5MB 100.00%
// two pointers
// O(N) O(1)
func reverseVowels(s string) string {
	vowels := "aeiouAEIOU"
	i, j := 0, len(s)-1
	runes := []rune(s)
	for i < j {
		if strings.ContainsRune(vowels, runes[i]) &&
			strings.ContainsRune(vowels, runes[j]) {
			runes[i], runes[j] = runes[j], runes[i]
			i++
			j--
		} else if strings.ContainsRune(vowels, runes[i]) {
			j--
		} else if strings.ContainsRune(vowels, runes[j]) {
			i++
		} else {
			i++
			j--
		}
	}
	return string(runes)
}

func main() {
	fmt.Println(reverseVowels("hello"))
}
