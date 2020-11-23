/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// brute force
// O(lg_{26}N) O(1)
func convertToTitle(n int) string {
	r := ""
	for n > 0 {
		n -= 1
		r = string((n%26)+'A') + r
		n /= 26
	}
	return r
}

func main() {
	fmt.Println(convertToTitle(1))
	fmt.Println(convertToTitle(28))
	fmt.Println(convertToTitle(701))
}
