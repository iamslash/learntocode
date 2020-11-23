/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 48ms 26.58% 8.1MB, 100.00%
// partial sum
// SumRange: O(1) O(N)
type NumArray struct {
	ps []int
}

func Constructor(nums []int) NumArray {
	ps := make([]int, len(nums)+1)
	for i, n := range nums {
		ps[i+1] = ps[i] + n
	}
	return NumArray{ps: ps}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.ps[j+1] - this.ps[i]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */

func main() {
	fmt.Println("hello world")
}
