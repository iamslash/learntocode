/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0 10
// 0 11
// 0 10 11
// 0 11 10

// if bits[i] == 1, move 2 units
// if bits[i] == 0 and i is last index, return true

// 0ms 100.00% 2.7MB 100.00%
// incremental traverse
// O(N) O(1)
func isOneBitCharacter(bits []int) bool {
	for i := 0; i < len(bits); i++ {
		if bits[i] == 1 {
			i++
		} else if bits[i] == 0 && i == len(bits)-1 {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println("hello world")
}
