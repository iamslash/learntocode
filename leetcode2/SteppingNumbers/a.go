/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 8ms 100.00% 6.6MB 100.00%
// BFS
// O(H) O(H)
func countSteppingNumbers(low int, high int) []int {
	rslt := []int{}
	if low > high {
		return rslt
	}
	if low == 0 {
		rslt = append(rslt, 0)
	}
	bfsq := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for len(bfsq) > 0 {
		top := bfsq[0]
		bfsq = bfsq[1:]
		if top < high {
			last := top % 10
			if last > 0 {
				bfsq = append(bfsq, top*10+last-1)
			}
			if last < 9 {
				bfsq = append(bfsq, top*10+last+1)
			}
		}
		if top >= low && top <= high {
			rslt = append(rslt, top)
		}
	}
	return rslt
}

func main() {
	fmt.Println("hello world")
}
