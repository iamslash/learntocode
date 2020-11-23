/* Copyright (C) 2020 by iamslash */

package main

// a b c
// d e f g

// 4ms 56.52% 3.1MB 84.57%
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func assemble(a, b []byte) string {
	i, j, k, m, n := 0, 0, 0, len(a), len(b)
	ans := make([]byte, m+n)
	for k < len(ans) {
		if i < m {
			ans[k] = a[i]
			k++
			i++
		}
		if j < n {
			ans[k] = b[j]
			k++
			j++
		}
	}
	return string(ans)
}
func reformat(s string) string {
	letters := []byte{}
	digits := []byte{}
	for i := 0; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			letters = append(letters, s[i])
		} else {
			digits = append(digits, s[i])
		}
	}
	if abs(len(letters)-len(digits)) > 1 {
		return ""
	}
	if len(letters) > len(digits) {
		return assemble(letters, digits)
	}
	return assemble(digits, letters)
}
