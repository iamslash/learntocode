/* Copyright (C) 2020 by iamslash */

package main

//   n : 7
//   E : [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
//           i
//   B : [f t t f t t f]
// cnt : 4

//   n : 4
//   E : [[0,2],[0,3],[1,2]]
//                       i
//   B : f t f f
// cnt :0

// Wrong Answer
// n: 4
// E: [[0,2],[0,3],[1,2]]
// B: [false,true,false,false]
// tree
// O(E) O(1)
func minTime(n int, E [][]int, B []bool) int {
	cnt := 0
	for i := len(E); i >= 0; i-- {
		if B[E[i][1]] == true {
			cnt++
			B[E[i][0]] = true
		}
	}
	return cnt * 2
}
