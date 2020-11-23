/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// ab ba
//
// ab  ba
// 11  11

// 4ms 63.16% 2.7MB 100.00%
// hash map
// O(N) O(N)
func isIsomorphic(a string, b string) bool {
	if len(a) != len(b) {
		return false
	}
	amap, bmap := make(map[byte]int), make(map[byte]int)
	for i := 0; i < len(a); i++ {
		aval, aok := amap[a[i]]
		bval, bok := bmap[b[i]]
		if aok != bok || aval != bval {
			return false
		}
		amap[a[i]] = i + 1
		bmap[b[i]] = i + 1
	}
	return true
}

func main() {
	fmt.Println(isIsomorphic("aba", "baa"))
}
