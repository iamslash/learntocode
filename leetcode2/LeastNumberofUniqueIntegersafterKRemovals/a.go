/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// 116ms 77.50% 11.6MB 100.00%
// hash map
// O(NlgN) O(N)
func findLeastNumOfUniqueInts(A []int, k int) int {
	cnts, n := make(map[int]int), len(A)
	for _, a := range A {
		cnts[a]++
	}
	keys := []int{}
	for k := range cnts {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return cnts[keys[i]] < cnts[keys[j]]
	})
	// fmt.Println(cnts)
	for i := 0; i < n && k > 0; i++ {
		// fmt.Printf("keys[i]: %d, cnts[keys[i]]: %d\n", keys[i], cnts[keys[i]])
		t := cnts[keys[i]]
		if k >= t {
			delete(cnts, keys[i])
		}
		k -= t
	}
	return len(cnts)
}
