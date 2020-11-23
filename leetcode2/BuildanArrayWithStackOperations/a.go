/* Copyright (C) 2020 by iamslash */

package main

//        a
// I: 1 2 3
//        j
// T: 1 3
// A: P P o P

//                n
// I: 1 2 3 4 5 6 7 8 9 10
//              j
// T: 2 3 4 5 8 9 10
// A: p o p p p p p

// 0ms 100.00% 2.3MB 87.07%
// two pointers
// O(N) O(N)
func buildArray(T []int, n int) []string {
	ans := []string{}
	for a, j := 1, 0; a <= n && j < len(T); a++ {
		ans = append(ans, "Push")
		if T[j] == a {
			j++
		} else {
			ans = append(ans, "Pop")
		}
	}
	return ans
}
