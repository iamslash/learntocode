/* Copyright (C) 2020 by iamslash */

package main

import "strings"

// 4ms 27.54% 2.5MB 14.52%
// brute force
// O(N^2) O(N)
func stringMatching(W []string) []string {
	ans := []string{}
	for _, u := range W {
		for _, v := range W {
			if u == v {
				continue
			}
			if strings.Contains(v, u) {
				ans = append(ans, u)
				break
			}
		}
	}
	return ans
}
