/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 1001
// 0110
// 0100
// 0010
// 0011
// 0101
// 0111
// 0000
// 0001

// // 20ms 44.84% 6MB 100.00%
// // bit manipulation
// // O(N) O(1)
// func missingNumber(A []int) int {
//   bm := 0
//   for i := 0; i < len(A); i++ {
//     bm ^= (i+1) ^ A[i]

//   }
//   return bm
// }

// 16ms 88.70% 6MB 100.00%
// O(N) O(1)
func missingNumber(A []int) int {
	sum := 0
	for _, num := range A {
		sum += num
	}
	return len(A)*(len(A)+1)/2 - sum
}

func main() {
	// A := []int{3, 0, 1}
	A := []int{9, 6, 4, 2, 3, 5, 7, 0, 1}
	fmt.Println(missingNumber(A))
}
