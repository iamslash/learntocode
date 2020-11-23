/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// brute force
// 0ms 100.00% 2.1MB 25.00%
func refine(s string) string {
	ss := []byte{}
	backCnt := 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '#' {
			backCnt++
		} else if backCnt > 0 {
			backCnt--
		} else {
			ss = append(ss, s[i])
		}
	}
	return string(ss)
}
func backspaceCompare(s string, t string) bool {
	return refine(s) == refine(t)
}

func main() {
	fmt.Println("hello world")
}
