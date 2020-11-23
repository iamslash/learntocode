/* Copyright (C) 2020 by iamslash */

package main

// avg: 6
//   A: 1 3 5 7 9 11
//      2 3 5 7 9 10
//      3 3 5 7 9 9
//      4 3 5 7 9 8
//      5 3 5 7 9 7
//      6 3 5 7 9 6
//        4 5 7 8
//        5 5 7 7
//        6 5 7 6
//          6 6
//

// 0ms 100.00% 2MB 83.46%
// math
// O(N) O(1)
func minOperations(n int) int {
	avg, ans := n, 0
	for i := 0; i < n/2; i++ {
		// fmt.Printf("i:%d, a: %d\n", i, avg - i -1)
		num := 2*i + 1
		ans += (avg - num)
	}
	return ans
}
