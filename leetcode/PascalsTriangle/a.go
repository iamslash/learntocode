/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.3MB 100.00%
// bruteforce
// O(N^2) O(N^2)
func generate(n int) [][]int {
	//
	r := make([][]int, n)
	for i := 0; i < n; i++ {
		// fmt.Printf("%d\n", i)
		r[i] = append(r[i], i+1)
		if i == 0 {
			r[0] = []int{1}
			continue
		}
		r[i] = make([]int, i+1)
		for j := 0; j < i/2+1; j++ {
			// fmt.Printf("  %d\n", j)
			if j == 0 {
				r[i][j], r[i][i] = 1, 1
				continue
			}
			v := r[i-1][j-1] + r[i-1][j]
			r[i][j], r[i][i-j] = v, v
		}
	}
	return r
}

func main() {
	fmt.Print(generate(5))
}
