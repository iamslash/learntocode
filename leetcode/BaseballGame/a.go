/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"strconv"
)

//   ops: 5 2 C D +
//  stck: 5 2
//   sum: 5 7

// 0ms 100.00% 2.6MB 100.00%
// brute force
// O(N) O(1)
func calPoints(ops []string) int {
	sum := 0
	stck := []int{}
	for _, op := range ops {
		switch op {
		case "+":
			stck = append(stck, stck[len(stck)-1]+stck[len(stck)-2])
			sum += stck[len(stck)-1]
		case "C":
			sum -= stck[len(stck)-1]
			stck = stck[:len(stck)-1]
		case "D":
			stck = append(stck, stck[len(stck)-1]+stck[len(stck)-1])
			sum += stck[len(stck)-1]
		default:
			num, _ := strconv.Atoi(op)
			stck = append(stck, num)
			sum += stck[len(stck)-1]
		}
	}
	return sum
}

func main() {
	fmt.Println("hello world")
}
