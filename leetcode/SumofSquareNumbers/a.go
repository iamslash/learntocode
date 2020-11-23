/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

// 0ms 100.00% 1.9MB 100.00%
// two pointers
// O(N) O(1)
func judgeSquareSum(c int) bool {
	a, b := 0, int(math.Sqrt(float64(c)))
	for a <= b {
		sum := a*a + b*b
		if sum < c {
			a++
		} else if sum > c {
			b--
		} else {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println("hello world")
}
