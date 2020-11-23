/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// hash, gcd
// O(N) O(1)
func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}
func hasGroupsSizeX(D []int) bool {
	cnts := make([]int, 10000)
	for _, num := range D {
		cnts[num]++
	}
	g := -1
	for i := 0; i < 10000; i++ {
		if cnts[i] > 0 {
			if g < 0 {
				g = cnts[i]
			} else {
				g = gcd(g, cnts[i])
			}
		}
	}
	return g > 1
}

func main() {
	fmt.Println("hello world")
}
