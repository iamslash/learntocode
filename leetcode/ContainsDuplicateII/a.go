/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// i
// 1 0 1 1
//   j
//
// 0 1
// 1 0

// // 24ms 30.09% 6.6MB 33.33%
// // two pointers
// // O(N) O(N)
// func containsNearbyDuplicate(A []int, k int) bool {
// 	nmap := make(map[int]int)
// 	i, j, n := 0, 0, len(A)
// 	for j < n && i <= j {
// 		nmap[A[j]]++
// 		// fmt.Printf("j: %2d ", j)
// 		// fmt.Println(nmap)
// 		if nmap[A[j]] > 1 {
// 			return true
// 		}
// 		if j-i >= k {
// 			nmap[A[i]]--
// 			if nmap[A[i]] <= 0 {
// 				delete(nmap, A[i])
// 			}
// 			i++
// 		}
// 		j++
// 	}
// 	return false
// }

// 16ms 76.99% 7.6MB 33.33%
// map
// O(N) O(N)
func containsNearbyDuplicate(A []int, k int) bool {
	M := make(map[int]int, len(A))
	for j, v := range A {
		if i, ok := M[v]; ok {
			if j-i <= k {
				return true
			}
		}
		M[v] = j
	}
	return false
}

func main() {
	fmt.Println(containsNearbyDuplicate([]int{1, 2, 3, 1}, 3))
	fmt.Println(containsNearbyDuplicate([]int{1, 0, 1, 1}, 1))
	fmt.Println(containsNearbyDuplicate([]int{1, 2, 3, 1, 2, 3}, 2))
	// M := make(map[int]int)
	// i, ok := M[3]
	// fmt.Println(i)
	// fmt.Println(ok)
	// fmt.Println(len(M))
}
