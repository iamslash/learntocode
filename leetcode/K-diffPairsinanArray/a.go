/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 20ms 90.14% 6.1MB 100.00%
// hash
// O(N) O(N)
func findPairs(A []int, k int) int {
	if k < 0 {
		return 0
	}
	rslt := 0
	cnts := make(map[int]int)
	for _, v := range A {
		cnts[v]++
	}
	if k == 0 {
		for _, v := range cnts {
			if v > 1 {
				rslt++
			}
		}
		return rslt
	}
	for key := range cnts {
		if _, ok := cnts[key+k]; ok {
			rslt++
		}
	}
	return rslt
}

func main() {
	// A := []int{3, 1, 4, 1, 5}
	// K = 2
	// A := []int{1, 2, 3, 4, 5}
	// K := 1
	A := []int{1, 3, 1, 5, 4}
	K := 0
	fmt.Println(findPairs(A, K))
}
