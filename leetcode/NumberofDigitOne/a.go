/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 23

// quo :  2
// div : 10

// 0ms 100.00% 2MB 100.00%
// recursion
// O(N) O(N)
func solve(n int, ump map[int]int) int {
	ans := 0
	if n <= 0 {
		return 0
	}
	if n <= 9 {
		return 1
	}
	quo, div := n, 1
	for quo/10 > 0 {
		quo /= 10
		div *= 10
	}
	ans += n / div * ump[div-1]
	if n/div > 1 {
		ans += div
	} else if n/div == 1 {
		ans += n%div + 1
	}
	ans += countDigitOne(n % div)

	return ans

}
func countDigitOne(n int) int {
	ump := map[int]int{9: 1}
	for i := 99; i <= n; i = i*10 + 9 {
		ump[i] = ump[i/10]*10 + (i/10 + 1)
	}
	// fmt.Println(ump)
	// return 0
	return solve(n, ump)
}

func main() {
	fmt.Println(countDigitOne(2356))
}
