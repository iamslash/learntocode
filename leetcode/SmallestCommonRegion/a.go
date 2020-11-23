/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 40ms 25.00% 8.1MB 100.00%
// LCA
// O(N) O(N)
func findSmallestRegion(R [][]string, a string, b string) string {
	parents := make(map[string]string)
	for _, regions := range R {
		for i := 1; i < len(regions); i++ {
			parents[regions[i]] = regions[0]
		}
	}
	visited := make(map[string]bool)
	for true {
		if _, ok := parents[a]; ok == false {
			break
		}
		if a == b {
			return a
		}
		visited[a] = true
		a = parents[a]
	}
	for true {
		if _, ok := parents[b]; ok == false {
			break
		}
		if _, ok := visited[b]; ok == true {
			return b
		}
		b = parents[b]
	}
	return a
}

func main() {
	fmt.Println("hello world")
}
