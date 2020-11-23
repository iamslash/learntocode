/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"sort"
)

// 4ms 73.08% 3.7MB 100.00%
// hash map
// O(N) O(N)
func numSpecialEquivGroups(A []string) int {
	groups := make(map[string]bool)
	for _, s := range A {
		a, b := []byte{}, []byte{}
		for i := range s {
			if i&1 > 0 {
				b = append(b, s[i])
			} else {
				a = append(a, s[i])
			}
		}
		sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
		sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })
		groups[string(a)+" "+string(b)] = true
	}
	return len(groups)
}

func main() {
	fmt.Println("hello world")
}
