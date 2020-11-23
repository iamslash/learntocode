/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// a b c d e f g h
// e f g h a b c d
// g h e f c d a b
// h g f e d c b a

// 1111 0000
// 1100 0011
// 1010 0101
// 1000 0100

// 0ms 100.00% 2.3MB 100.00%
// recursive shift
// O(1) O(1)
func reverseBits(n uint32) uint32 {
	n = (n >> 16) | (n << 16)
	n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8)
	n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4)
	n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2)
	n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)
	return n
}

func main() {
	fmt.Println("hello world")
}
