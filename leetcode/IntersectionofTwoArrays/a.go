/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 4ms 87.43% 4.4MB 100.00%
// hashmap
// O(N) O(N)
func intersection(nums1 []int, nums2 []int) []int {
	rst := []int{}
	map1 := make(map[int]bool)
	for _, num := range nums1 {
		map1[num] = true
	}
	for _, num := range nums2 {
		if _, ok := map1[num]; ok {
			delete(map1, num)
			rst = append(rst, num)
		}
	}
	return rst
}

func main() {
	fmt.Println(intersection([]int{1, 2, 4, 5}, []int{1, 5, 2}))
}
