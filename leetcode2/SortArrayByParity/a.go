/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 82.42% 4.7MB 100.00%
// two pointers
// O(N) O(1)
func sortArrayByParity(A []int) []int {
	i, j := 0, len(A)-1
	for i < j {
		for i < j && (A[i]&1) == 0 {
			i++
		}
		for i < j && (A[j]&1) == 1 {
			j--
		}
		if i < j {
			A[i], A[j] = A[j], A[i]
		}
		// fmt.Printf("%d %d\n", i, j)
	}
	return A
}

func main() {
	fmt.Println("hello world")
}
