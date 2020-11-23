/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"strconv"
)

// add 1
// get binary representation
// remove LMB which is 1

// 0:   0
// 1:   1    0
// 2:  10    1
// 3:  11   00
// 4: 100   01
// 5: 101   10
// 6: 110   11
// 7: 111  000

// 0ms 100.00% 1.9MB 100.00%
// math
// O(N) O(1)
func encode(num int) string {
	num++
	bin := strconv.FormatInt(int64(num), 2)
	return bin[1:]
}

func main() {
	fmt.Println("hello world")
}
