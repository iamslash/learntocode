/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0000 0100
// 0000 0010
//----------
// 0000 0110
// 0000 0111

// 0000 0101
// 0000 0010
//-----------
// 0000 0111
// 0000 1000

// 0ms 100.00% 1.9MB 100.00%
// bit manipulation
// O(1) O(1)
func hasAlternatingBits(n int) bool {
	bm := n >> 1
	return (bm+n)&(bm+n+1) == 0
}

func main() {
	fmt.Println("hello world")
}
