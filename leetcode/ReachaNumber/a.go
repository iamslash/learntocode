/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

//         0
//       /   \
//     -1      1
//

// Runtime Error : -1000000000
// // BFS
// // O(2^T) O(2^T)
// func reachNumber(tgt int) int {
// 	q := []int{0}
// 	d := 0
// 	for len(q) > 0 {
// 		n := len(q)
// 		d++
// 		for i := 0; i < n; i++ {
// 			u := q[0]
// 			q = q[1:]
// 			if u == tgt {
// 				return d - 1
// 			}
// 			q = append(q, u+d, u-d)
// 		}
// 		// fmt.Printf("%d :", d)
// 		// fmt.Println(q)
// 	}
// 	return -1
// }

// 0ms 100.00% 1.9MB 100.00%
// math
// O(N) O(1)
func reachNumber(tgt int) int {
	var sum, stp int
	if tgt < 0 {
		tgt = -tgt
	}
	for {
		sum += stp
		if sum >= tgt {
			break
		}
		stp++
	}
	if (sum-tgt)&1 == 0 {
		return stp
	}
	if stp&1 == 0 {
		return stp + 1
	}
	return stp + 2
}

func main() {
	fmt.Println(reachNumber(2))
}
