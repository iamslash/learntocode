/* Copyright (C) 2020 by iamslash */

package main

//        i
// s: abcabc
//          j
//
// c: a b c
//    0 1 1
// a: 10
//
//    abc
//    abca
//     bca
//    abcab
//     bcab
//      cab
//    abcabc
//     bcabc
//      cabc
//       abc

// 4ms 100.00% 4.2MB 100.00%
// sliding window
// O(N) O(1)
func numberOfSubstrings(s string) int {
	i, j, ans, n := 0, 0, 0, len(s)
	cnt := []int{0, 0, 0}
	for j < n {
		cnt[s[j]-'a']++
		j++
		for cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
			cnt[s[i]-'a']--
			i++
		}
		ans += i
	}
	return ans
}
