/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//       i
// 2 2 2 1 2 2 1 2 2 2
//             j
// 0 3 6 10

// 120ms 85.71% 7.4MB 100.00%
// hash map
// O(N) O(N)
func numberOfSubarrays(A []int, k int) int {
	oddIdx := []int{-1}
	for i, num := range A {
		if (num & 1) > 0 {
			oddIdx = append(oddIdx, i)
		}
	}
	oddIdx = append(oddIdx, len(A))
	sum := 0
	for i := 1; i+k < len(oddIdx); i++ {
		l := oddIdx[i] - oddIdx[i-1]
		r := oddIdx[i+k] - oddIdx[i+k-1]
		sum += l * r
	}
	return sum
}

// 1 1 2 1 1
//
//     i
// -1 0 1 3 4 5
//

func main() {
	A := []int{2, 2, 2, 1, 2, 2, 1, 2, 2, 2}
	k := 2
	// A := []int{1, 1, 2, 1, 1}
	// k := 3
	fmt.Println(numberOfSubarrays(A, k))
}
