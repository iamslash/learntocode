/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"strings"
)

// 4ms 98.97% 6MB 100.00%
// stack
// O(N) O(N)
func minRemoveToMakeValid(s string) string {
	stck := []int{}
	bs := []byte(s)
	for i, b := range bs {
		if b == '(' {
			stck = append(stck, i)
		} else if b == ')' {
			if len(stck) > 0 {
				stck = stck[:len(stck)-1]
			} else {
				bs[i] = '*'
			}
		}
	}
	for len(stck) > 0 {
		bs[stck[len(stck)-1]] = '*'
		stck = stck[:len(stck)-1]
	}
	return strings.ReplaceAll(string(bs), "*", "")
}

//     i
// * * ( (
//
// stck:

func main() {
	fmt.Println(minRemoveToMakeValid("))(("))
}
