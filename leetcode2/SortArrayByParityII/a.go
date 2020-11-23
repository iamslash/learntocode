/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 20ms 94.03% 6.2MB 100.00%
// two pointers
// O(N) O(1)
func sortArrayByParityII(A []int) []int {
	i, j, n := 0, 1, len(A)
	for i < n && j < n {
		for i < n && A[i]&1 == 0 {
			i += 2
		}
		for j < n && A[j]&1 == 1 {
			j += 2
		}
		if i < n && j < n {
			A[i], A[j] = A[j], A[i]
			i += 2
			j += 2
		}
	}
	return A
}

func main() {
	fmt.Println("hello world")
}
