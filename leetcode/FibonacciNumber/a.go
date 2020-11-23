/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 1.9MB 100.00%
// fibonacci
// O(N) O(1)
func fib(N int) int {
	if N < 2 {
		return N
	}
	a := 0
	b := 1
	for i := 2; i <= N; i++ {
		a, b = b, a+b
	}
	return b
}

func main() {
	for i := 2; i < 5; i++ {
		fmt.Println(fib(i))
	}
}
