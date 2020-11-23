/* Copyright (C) 2020 by iamslash */

package main

//  odd[i]: the number of subarray ends with A[i] and sum of subarray is odd
// even[i]: the number of subarray ends with A[i] and sum of subarray is even.
//
// if A[i] odd
//   odd[i] = even[i-1] + 1
//  even[i] = odd[i-1]
// if A[i] even
//   odd[i] = odd[i-1]
//  even[i] = even[i-1] + 1

//    A:   1 3 5
//  odd: 0 1 1 2
// even: 0 0 1 1
//  ans: 0 1 2 4

// 160ms 66.67% 9.4MB 11.67%
// dynamic programming
// O(N) O(1)
var MOD int = 1000000007

func numOfSubarrays(A []int) int {
	ans, odd, even := 0, 0, 0
	for _, a := range A {
		if a&1 == 1 {
			tmp := odd
			odd = even + 1
			even = tmp
		} else {
			even++
		}
		ans = (ans + odd) % MOD
	}
	return ans
}
