/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"strings"
)

// 0ms 100.00% 2.3MB 100.00%
// hash map
// O(N) O(N)
func uncommonFromSentences(a string, b string) []string {
	aMap := make(map[string]int)
	bMap := make(map[string]int)
	for _, s := range strings.Split(a, " ") {
		aMap[s]++
	}
	for _, s := range strings.Split(b, " ") {
		bMap[s]++
	}
	ans := []string{}
	for k, v := range aMap {
		if v == 1 {
			if _, ok := bMap[k]; ok == false {
				ans = append(ans, k)
			}
		}
	}
	for k, v := range bMap {
		if v == 1 {
			if _, ok := aMap[k]; ok == false {
				ans = append(ans, k)
			}
		}
	}
	return ans
}

func main() {
	a := "this apple is sweet"
	b := "this apple is sour"
	fmt.Println(uncommonFromSentences(a, b))
}
