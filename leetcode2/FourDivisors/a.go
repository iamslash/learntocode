/* Copyright (C) 2020 by iamslash */

package main

// 44ms 75.00% 5.4MB 42.86%
// brute force
// O(N^2) O(1)
func getSumDiv(a int) int {
	sum, cnt := 0, 0
	for u := 1; u*u <= a; u++ {
		quo, rem := a/u, a%u
		if rem == 0 {
			if u == quo {
				cnt += 1
				sum += u
			} else {
				cnt += 2
				sum += u + quo
			}
		}
		if cnt > 4 {
			return 0
		}
	}
	if cnt < 4 {
		return 0
	}
	return sum
}
func sumFourDivisors(A []int) int {
	ans := 0
	for _, a := range A {
		ans += getSumDiv(a)
		// fmt.Println(ans)
	}
	return ans
}
