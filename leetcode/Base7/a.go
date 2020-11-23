/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
)

// 0ms 100.00% 2MB 100.00%
// math
// O(N) O(1)
func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}
func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	bNeg := false
	if num < 0 {
		bNeg = true
	}
	num = abs(num)
	rst := ""
	for num > 0 {
		rem := num % 7
		rst = fmt.Sprintf("%d%s", rem, rst)
		num /= 7
	}
	if bNeg {
		rst = "-" + rst
	}
	return rst
}

func main() {
	fmt.Println(convertToBase7(100))
}
