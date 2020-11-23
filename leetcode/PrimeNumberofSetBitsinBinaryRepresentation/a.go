/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"math/bits"
)

// // 12ms 48.00% 2MB 50.00%
// // hashset
// // O(N) O(1)
// func getOneCnt(n int) int {
// 	cnt := 0
// 	for n > 0 {
// 		if n&1 == 1 {
// 			cnt++
// 		}
// 		n >>= 1
// 	}
// 	return cnt
// }
// func countPrimeSetBits(L int, R int) int {
// 	primes := map[int]bool{
// 		2: true, 3: true, 5: true, 7: true, 11: true, 13: true,
// 		17: true, 19: true, 23: true, 27: true, 29: true, 31: true,
// 	}
// 	rslt := 0
// 	for num := L; num <= R; num++ {
// 		cnt := getOneCnt(num)
// 		if _, ok := primes[cnt]; ok {
// 			rslt++
// 		}
// 	}
// 	return rslt
// }

// 12ms 48.00% 2MB 50.00%
// hashset
// O(N) O(1)
func isPrime(x int) bool {
	return x == 2 || x == 3 || x == 5 || x == 7 ||
		x == 11 || x == 13 || x == 17 || x == 19
}
func countPrimeSetBits(L, R int) int {
	cnt := 0
	for num := L; num <= R; num++ {
		cntOne := bits.OnesCount(uint(num))
		if isPrime(cntOne) {
			cnt++
		}
	}
	return cnt
}

func main() {
	fmt.Println("hello world")
}
