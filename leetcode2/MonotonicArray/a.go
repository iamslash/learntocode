/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//        i
//   A: 1 2 2 3
// inc: true
// dec: true

// 64ms 76.19% 6.5MB 100.00%
// linear traversal
// O(N) O(1)
func isMonotonic(A []int) bool {
	inc, dec := true, true
	for i := range A {
		if i > 0 {
			inc = inc && (A[i] >= A[i-1])
			dec = dec && (A[i] <= A[i-1])
		}
	}
	return inc || dec
}

func main() {
	fmt.Println("hello world")
}
