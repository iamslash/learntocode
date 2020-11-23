/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// |  |
// dcab
//  ||
//
// [[0, 3], [1, 2]]

// 100ms 100.00% 21.1MB 100.00%
// union-find
// O(N) O(N)
func find(ds []int, u int) int {
	if ds[u] == u {
		return u
	}
	ds[u] = find(ds, ds[u])
	return ds[u]
}
func merge(ds []int, u, v int) {
	u = find(ds, u)
	v = find(ds, v)
	if u != v {
		ds[u] = v
	}
}
func smallestStringWithSwaps(s string, P [][]int) string {
	rslt := []byte(s)
	ds := make([]int, len(s))
	for i := 0; i < len(ds); i++ {
		ds[i] = i
	}
	M := make([][]int, len(s))
	for _, p := range P {
		merge(ds, p[0], p[1])
	}
	for i, _ := range s {
		u := find(ds, i)
		M[u] = append(M[u], i)
	}
	for _, idxs := range M {
		bs := []byte{}
		for _, idx := range idxs {
			bs = append(bs, s[idx])
		}
		sort.Slice(bs, func(i, j int) bool {
			return bs[i] < bs[j]
		})
		for i, idx := range idxs {
			rslt[idx] = bs[i]
		}
	}
	return string(rslt)
}

func main() {
	fmt.Println("hello world")
}
