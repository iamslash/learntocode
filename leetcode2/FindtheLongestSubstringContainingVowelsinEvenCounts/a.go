/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 100.00% 6.2MB 100.00%
// hash map
// O(N) O(1)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func findTheLongestSubstring(s string) int {
	bm, ans := 0, 0
	bmIdx := make([]int, 32)
	vowelNum := [26]int{1, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0}
	for i := 0; i < len(bmIdx); i++ {
		bmIdx[i] = -1
	}
	for i := 0; i < len(s); i++ {
		bm ^= vowelNum[s[i]-'a']
		if bm != 0 && bmIdx[bm] == -1 {
			bmIdx[bm] = i
		}
		ans = max(ans, i-bmIdx[bm])
	}
	return ans
}

func main() {
	fmt.Println("hello world")
}
