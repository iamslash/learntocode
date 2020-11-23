/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

// // 872ms 20.68% 66.8MB 100.00%
// // sieve of eratosthenes
// // O(N) O(N)
// func countPrimes(n int) int {
// 	primeset := make(map[int]struct{})
// 	for i := 2; i < n; i++ {
// 		primeset[i] = struct{}{}
// 	}
// 	for i := 2; i <= int(math.Sqrt(float64(n))); i++ {
// 		if _, ok := primeset[i]; ok {
// 			for j := i * i; j < n; j += i {
// 				delete(primeset, j)
// 			}
// 		}
// 	}
// 	return len(primeset)
// }

// 8ms 81.69% 5MB 100.00%
// sive of ertosthenes
// O(N) O(N)
func countPrimes(n int) int {
	if n < 2 {
		return 0
	}
	var cnt int
	noprimes := make([]bool, n)
	noprimes[0], noprimes[1] = true, true
	for i := 2; i < n; i++ {
		if noprimes[i] {
			continue
		}
		cnt++
		for j := i * i; j < n; j += i {
			noprimes[j] = true
		}
	}
	return cnt
}

func main() {
	fmt.Println(countPrimes(5))
}
