package main

import "fmt"

// 292ms 12.00% 35.8MB 100.00%
// dynamic programming
// O(AB) O(AB)
func lcs(a string, b string) string {
	m, n := len(a), len(b)
	C := [1001][1001]string{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if a[i] == b[j] {
				C[i+1][j+1] = C[i][j] + string(a[i])
			} else {
				C[i+1][j+1] = C[i][j+1]
				if len(C[i+1][j]) > len(C[i][j+1]) {
					C[i+1][j+1] = C[i+1][j]
				}
			}
		}
	}
	return C[m][n]
}

func shortestCommonSupersequence(a string, b string) string {
	i, j := 0, 0
	ans := ""
	for _, v := range lcs(a, b) {
		c := uint8(v)
		for a[i] != c {
			ans += a[i : i+1]
			i++
		}
		for b[j] != c {
			ans += b[j : j+1]
			j++
		}
		ans += string(c); i++; j++
	}

	return ans + a[i:] + b[j:]
}

func main() {
	a := "abac"
	b := "cab"
	fmt.Println(shortestCommonSupersequence(a, b))
}
