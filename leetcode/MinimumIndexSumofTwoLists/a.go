/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 28ms 98.33% 6.6MB 10.00%
// hash
// O(AB) O(B)
func findRestaurant(A []string, B []string) []string {
	bIdxs := make(map[string]int)
	for j, s := range B {
		bIdxs[s] = j
	}
	rslt := []string{}
	minIdx := len(A) + len(B)
	for iIdx, s := range A {
		if jIdx, ok := bIdxs[s]; ok {
			sumIdx := iIdx + jIdx
			if sumIdx == minIdx {
				rslt = append(rslt, s)
			} else if sumIdx < minIdx {
				minIdx = sumIdx
				rslt = []string{s}
			}
		}
	}
	return rslt
}

func main() {
	A := []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	B := []string{"KFC", "Shogun", "Burger King"}
	fmt.Println(findRestaurant(A, B))
}
