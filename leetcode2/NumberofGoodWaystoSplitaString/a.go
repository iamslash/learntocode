/* Copyright (C) 2020 by iamslash */

package main

//                 i
//            s: a a c a b a
//  leftCharCnt: a
//               1
// rightCharCnt: a b c
//               4 1 1
//  leftDistCnt: 1
// rightDistCnt: 3
//          ans: 0

// 4ms 97.67% 3.8MB 88.37%
// hash map
// O(1) O(1)
func numSplits(s string) int {
	leftCharCnt, rightCharCnt := make([]int, 26), make([]int, 26)
	leftDistCnt, rightDistCnt, ans := 0, 0, 0

	for i := 0; i < len(s); i++ {
		if rightCharCnt[s[i]-'a'] == 0 {
			rightDistCnt++
		}
		rightCharCnt[s[i]-'a']++
	}

	for i := 0; i < len(s)-1; i++ {
		idx := s[i] - 'a'
		if leftCharCnt[idx] == 0 {
			leftDistCnt++
		}
		leftCharCnt[idx]++
		rightCharCnt[idx]--
		if rightCharCnt[idx] == 0 {
			rightDistCnt--
		}
		if leftDistCnt == rightDistCnt {
			ans++
		}
	}
	return ans
}
