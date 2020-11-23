/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
// brute force
// O(N) O(1)
func upperCase(b byte) bool {
	i := b - 'A'
	return i >= 0 && i < 26
}
func detectCapitalUse(s string) bool {
	capCnt, bFirstCap := 0, false
	for i := 0; i < len(s); i++ {
		if upperCase(s[i]) {
			capCnt++
			if i == 0 {
				bFirstCap = true
			}
		}
	}
	if (bFirstCap && capCnt == 1) ||
		(capCnt == len(s)) ||
		capCnt == 0 {
		return true
	}
	return false
}

func main() {
	fmt.Println(detectCapitalUse("USA"))
	fmt.Println(detectCapitalUse("FlaG"))
}
