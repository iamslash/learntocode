/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.2MB, 100.00%
// hash map
// O(N) O(1)
func findTheDifference(s string, t string) byte {
	cnts := make([]int, 26)
	for _, rune := range s {
		cnts[rune-'a']++
	}
	for _, rune := range t {
		i := rune - 'a'
		if cnts[i] == 0 {
			return byte(rune)
		}
		cnts[i]--
	}
	return 'a'
}

func main() {
	fmt.Println(findTheDifference("abcd", "abcde"))
}
