/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//    k: 3
//                                 i
//    s: d d e e d d a b c c b d a a
//                   j
// stck: 2 2 2

// 0ms 100.00% 4.2MB 100.00%
// two pointers
// O(N) O(N)
func removeDuplicates(s string, k int) string {
	i, j, n := 0, 0, len(s)
	bytes := []byte(s)
	stack := []int{}
	for i < n {
		bytes[j] = bytes[i]
		if j == 0 || bytes[j] != bytes[j-1] {
			stack = append(stack, 1)
		} else if stack[len(stack)-1]++; stack[len(stack)-1] == k {
			stack = stack[:len(stack)-1]
			j -= k
		}
		i++
		j++
	}
	return string(bytes[:j])
}

func main() {
	fmt.Println(removeDuplicates("pbbcggttciiippooaais", 2))
}
