/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

//    A: 1 2 5
//    B: 2 4
//  sum: 14
// half: 7
// diff: 1

// 68ms 67.65% 6.8MB 100.00
// math
// O(N) O(1)
func fairCandySwap(A []int, B []int) []int {
	aSum, bSum := 0, 0
	aMap := make(map[int]bool)
	for _, v := range A {
		aSum += v
		aMap[v] = true
	}
	for _, v := range B {
		bSum += v
	}
	diff := (aSum - bSum) / 2
	for _, v := range B {
		if _, ok := aMap[diff+v]; ok {
			return []int{diff + v, v}
		}
	}
	return []int{}
}

func main() {
	fmt.Println("hello world")
}
