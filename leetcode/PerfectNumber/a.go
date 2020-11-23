/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"math"
)

// 0ms 100.00% 1.9MB 100.00%
// math
// O(sqrt(N)) O(1)
func checkPerfectNumber(num int) bool {
	if num == 1 {
		return false
	}
	sum := 1
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num%i == 0 {
			sum += i
			sum += num / i
		}
	}
	return sum == num
}

func main() {
	fmt.Println(checkPerfectNumber(28))
}
