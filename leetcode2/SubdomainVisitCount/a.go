/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"strconv"
	"strings"
)

// discuss.leetcode.com

// 8ms 81.82% 6MB 100.00%
// hash map
// O(N) O(N)
func subdomainVisits(D []string) []string {
	dom2cntMap := make(map[string]int)
	for _, s := range D {
		pairs := strings.Split(s, " ")
		cnt, _ := strconv.Atoi(pairs[0])
		words := strings.Split(pairs[1], ".")
		domain := ""
		for i := len(words) - 1; i >= 0; i-- {
			word := words[i]
			sep := ""
			if len(domain) > 0 {
				sep = "."
			}
			domain = word + sep + domain
			dom2cntMap[domain] += cnt
		}
	}
	rslt := []string{}
	for key, val := range dom2cntMap {
		rslt = append(rslt, fmt.Sprintf("%d %s", val, key))
	}
	return rslt
}

func main() {
	fmt.Println("hello world")
}
