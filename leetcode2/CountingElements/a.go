/* Copyright (C) 2020 by iamslash */

package main

// 0 1 2 3 5
// 0 1 1 2 1

// 1 2
// 2 1

// // 4ms 7.00% 2.4MB 5.21%
// func countElements(A []int) int {
// 	cnts := make(map[int]int)
// 	for _, a := range A {
// 		cnts[a]++
// 	}
// 	keys := []int{}
// 	for k, _ := range cnts {
// 		keys = append(keys, k)
// 	}
// 	sort.Ints(keys)
// 	ans := 0
// 	for i := 1; i < len(keys); i++ {
// 		if keys[i-1]+1 == keys[i] {
// 			ans += cnts[keys[i-1]]
// 		}
// 	}
// 	return ans
// }

// 0ms 100.00% 2.3MB 33.33%
func countElements(A []int) int {
	cnts := make(map[int]int)
	for _, a := range A {
		cnts[a]++
	}
	ans := 0
	for k, v := range cnts {
		if _, ok := cnts[k+1]; ok {
			ans += v
		}
	}
	return ans
}
