/* Copyright (C) 2019 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 72ms 96.67% 10.4MB 100.00%
// sort
// O(N) O(N)
func findRelativeRanks(A []int) []string {
	B := make([]int, len(A))
	copy(B, A)
	sort.Slice(B, func(i int, j int) bool {
		return B[i] > B[j]
	})
	num2idx := make(map[int]int)
	for i := 0; i < len(A); i++ {
		num2idx[A[i]] = i
	}
	rst := make([]string, len(A))
	for i := 0; i < len(B); i++ {
		s := fmt.Sprintf("%d", i+1)
		if i == 0 {
			s = "Gold Medal"
		} else if i == 1 {
			s = "Silver Medal"
		} else if i == 2 {
			s = "Bronze Medal"
		}
		rst[num2idx[B[i]]] = s
	}
	return rst
}

func main() {
	fmt.Println(findRelativeRanks([]int{10, 3, 8, 9, 4}))
}
