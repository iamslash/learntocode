/* Copyright (C) 2020 by iamslash */

package main

import "sort"

// dynamic programming, sort
// O(NlgN) O(N)
func getVal(cnts map[int]int, u int) int {
	// base
	if u == 1 {
		return 0
	}
	if v, ok := cnts[u]; ok {
		return v
	}
	step := 1
	if u%2 == 0 {
		step += getVal(cnts, u/2)
	} else {
		step += getVal(cnts, 3*u+1)
	}
	cnts[u] = step
	return step
}
func getKth(lo int, hi int, k int) int {
	if hi-lo == 0 {
		return lo
	}
	n := hi - lo + 1
	vals := make([]int, n)
	idxs := make([]int, n)
	cnts := make(map[int]int)
	for i := 0; i < n; i++ {
		idxs[i] = i
		vals[i] = getVal(cnts, lo+i)
	}
	sort.Slice(idxs, func(i, j int) bool {
		u, v := idxs[i], idxs[j]
		if vals[u] == vals[v] {
			return u < v
		}
		return vals[u] < vals[v]
	})
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		ans[i] = lo + idxs[i]
	}
	// fmt.Println(ans)
	return ans[k-1]
}
