/* Copyright (C) 2020 by iamslash */

package main

//    dict: ab cd yz
//           i
// dictMap: *b a* *d c* *z y*

// 168ms 90.48% 40.1MB 52.38%
// hash map
// O(NM) O(NM)
func differByOne(dict []string) bool {
	dictMap := make(map[string]bool)
	for _, s := range dict {
		ss := []byte(s)
		for i := 0; i < len(s); i++ {
			t := ss[i]
			ss[i] = '*'
			if _, ok := dictMap[string(ss)]; ok {
				return true
			}
			dictMap[string(ss)] = true
			ss[i] = t
		}
	}
	return false
}
