/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// just care about my deposits
// pays with $5 : cnt5++
// pays with $10: cnt10++, cnt5--
// pays with $20: cnt10--, cnt5-- or cnt5 -= 3

// 16ms 81.40% 5.8MB 100.00%
// greedy approach
// O(N) O(1)
func lemonadeChange(B []int) bool {
	cnt5, cnt10 := 0, 0
	for _, bill := range B {
		if bill == 5 {
			cnt5++
		} else if bill == 10 {
			cnt5--
			cnt10++
		} else if cnt10 > 0 {
			cnt10--
			cnt5--
		} else {
			cnt5 -= 3
		}
		if cnt5 < 0 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println("hello world")
}
