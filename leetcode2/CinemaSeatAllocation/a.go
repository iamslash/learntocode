/* Copyright (C) 2020 by iamslash */

package main

// 1 2 3 | 4 5 6 7 | 8 9 10
//   ---------
//             ----------
//         -------
// 1 2 4 | 8 16 32 64 | 128 256 512

// 88ms 100.00% 7.2MB 65.00%
// bit manipulation
// O(N) O(N)
func maxNumberOfFamilies(n int, R [][]int) int {
	reserved := make(map[int]int)
	for _, seat := range R {
		reserved[seat[0]-1] |= 1 << (seat[1] - 1)
	}
	ans := 0
	bms := []int{2 + 4 + 8 + 16, 32 + 64 + 128 + 256, 8 + 16 + 32 + 64}
	for _, seats := range reserved {
		cnt := 0
		if seats&bms[0] == 0 {
			cnt++
		}
		if seats&bms[1] == 0 {
			cnt++
		}
		if (seats&bms[2] == 0) && cnt == 0 {
			cnt++
		}
		ans += cnt
	}
	return ans + (n-len(reserved))*2
}
