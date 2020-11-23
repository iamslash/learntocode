/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 100.00%
// Linear traversal
// O(N) O(1)
func numberOfLines(W []int, s string) []int {
	widthMap := make([]int, 26)
	for i, width := range W {
		widthMap[i] = width
	}
	row, col := 1, 0
	for i := 0; i < len(s); i++ {
		w := widthMap[s[i]-'a']
		if col+w > 100 {
			row++
			col = w
		} else {
			col += w
		}
	}
	return []int{row, col}
}

func main() {
	fmt.Println("hello world")
}
