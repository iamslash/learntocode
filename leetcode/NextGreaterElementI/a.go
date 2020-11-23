/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// // 8ms 43.94% 8.1MB 100.00%
// // stack
// // O(max(A,B)) O(A)
// func nextGreaterElement(A []int, B []int) []int {
// 	num2idx := make(map[int]int)
// 	rslt := make([]int, len(A))
// 	stck := []int{}
// 	for i := 0; i < len(A); i++ {
// 		num2idx[A[i]] = i
// 		rslt[i] = -1
// 	}
// 	for i := 0; i < len(B); i++ {
// 		for len(stck) > 0 && stck[len(stck)-1] < B[i] {
// 			num := stck[len(stck)-1]
// 			stck = stck[:len(stck)-1]
// 			if _, ok := num2idx[num]; ok {
// 				rslt[num2idx[num]] = B[i]
// 			}
// 		}
// 		stck = append(stck, B[i])
// 	}
// 	return rslt
// }

// 8ms 43.94% 6.6MB 100.00%
// hash
// O(N) O(N)
// N: max(A, B)
func nextGreaterElement(A []int, B []int) []int {
	num2idx := make(map[int]int)
	for i := 0; i < len(B); i++ {
		num2idx[B[i]] = i
	}
	rslt := make([]int, 0, len(B))
	for i := 0; i < len(A); i++ {
		idx := num2idx[A[i]]
		var j int
		for j = idx + 1; j < len(B); j++ {
			if B[j] > A[i] {
				rslt = append(rslt, B[j])
				break
			}
		}
		if j == len(B) {
			rslt = append(rslt, -1)
		}
	}
	return rslt
}

func main() {
	A := []int{4, 1, 2}
	B := []int{1, 3, 4, 2}
	fmt.Println(nextGreaterElement(A, B))
}
