/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// names: gta gta(1) gta avalon gta(1)
// gta gta(1) avalon
//   2      0
// names: gta gta(1) gta(2)

//                    i
// names: ["wano","wano","wano","wano"]
// wano wano(1)
//    1

// 196ms 54.65% 11.7MB 100.00%
// hash map
// O(N) O(N)
func getFolderNames(names []string) []string {
	cntMap := make(map[string]int)
	for i := 0; i < len(names); i++ {
		u := names[i]
		if _, ok := cntMap[u]; ok {
			n := cntMap[u] + 1
			for true {
				if _, ok := cntMap[fmt.Sprintf("%s(%d)", u, n)]; ok == false {
					break
				}
				n++
			}
			cntMap[u] = n
			v := fmt.Sprintf("%s(%d)", u, n)
			cntMap[v] = 0
			names[i] = v
		} else {
			cntMap[u] = 0
		}
	}
	return names
}
