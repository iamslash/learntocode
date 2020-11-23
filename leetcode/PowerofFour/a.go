/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//  4  00000100
// 16  00010000
// 64  01000000

// math
// O(lg4N)
func isPowerOfFour(num int) bool {
	if num == 0 {
		return false
	}
	for num%4 == 0 {
		num /= 4
	}
	return num == 1
}

func main() {
	for i := 0; i < 17; i++ {
		fmt.Println(isPowerOfFour(i))
	}
}
