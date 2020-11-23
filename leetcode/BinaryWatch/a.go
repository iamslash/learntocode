/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2.9MB 100.00%
// bit manipulation
// O(1) O(1)
func getUsedBits(num int) int {
	cnt := 0
	for num > 0 {
		num = num & (num - 1)
		cnt++
	}
	return cnt
}

func readBinaryWatch(num int) []string {
	rst := []string{}
	for h := 0; h < 12; h++ {
		for m := 0; m < 60; m++ {
			if getUsedBits(h)+getUsedBits(m) == num {
				rst = append(rst, fmt.Sprintf("%d:%02d", h, m))
			}
		}
	}
	return rst
}

func main() {
	fmt.Println(readBinaryWatch(1))
}
