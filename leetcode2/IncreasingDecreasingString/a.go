/* Copyright (C) 2020 by iamslash */

package main

import "sort"

//       i
//    s: a a a a b b b b c c c c
//       j
// cnts: a b c
//       2 2 2
//
//  ans: a b c c b a

// l e e t c o d e
// cnts: c d e l o t
//       1 1 2 1 1

// 16ms 18.28% 6.4MB 20.48%
// hash map
// O(N) O(N)
func sortString(s string) string {
	n := len(s)
	cnts := make(map[int]int)
	for _, c := range s {
		cnts[int(c)]++
	}
	keys := []int{}
	for k := range cnts {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	ans := ""
	for len(ans) < n {
		for i := 0; i < len(keys) && len(ans) < n; i++ {
			if cnts[keys[i]] > 0 {
				ans += string(byte(keys[i]))
				cnts[keys[i]]--
			}
		}
		for i := len(keys) - 1; i >= 0 && len(ans) < n; i-- {
			if cnts[keys[i]] > 0 {
				ans += string(byte(keys[i]))
				cnts[keys[i]]--
			}
		}
	}
	return ans
}
