/* Copyright (C) 2020 by iamslash */

package main

//      i
// A: 0 1 1 1 0 1 1 0 1
//           j
// k: 0

//              i
//   A: 1 1 0 0 1 1 1 0 1
//                        j
//   k: 0
// ans: 5

// // 40ms 92.55% 6.7MB 81.92%
// // two pointers
// // O(N) O(1)
// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }
// func longestSubarray(A []int) int {
// 	i, j, n, k, ans := 0, 0, len(A), 1, 0
// 	for j = 0; j < n; j++ {
// 		if A[j] == 0 {
// 			k--
// 		}
// 		for k < 0 {
// 			if A[i] == 0 {
// 				k++
// 			}
// 			i++
// 		}
// 		ans = max(ans, j-i)
// 	}
// 	return ans
// }

//            i
//   A: 1 1 0 0 1 1 1 0 1
//                    j
//   k: -
// ans: 0

// sliding window not shrink
// O(N) O(1)
func longestSubarray(A []int) int {
	i, j, n, k := 0, 0, len(A), 1
	for j = 0; j < n; j++ {
		if A[j] == 0 {
			k--
		}
		if k < 0 {
			i++
			if A[i] == 0 {
				k++
			}
		}
	}
	return j - i
}
