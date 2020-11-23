package main

import "fmt"
import "sort"

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func smallestRangeII(A []int, K int) int {
	n := len(A)
	sort.Ints(A)
	ans := A[n-1] - A[0]
	for i := 1; i < n; i++ {
		hi := max(A[n-1]-K, A[i-1]+K)
		lo := min(A[0]+K, A[i]-K)
		ans = min(ans, hi-lo)
		// fmt.Printf("i: %d, hi:%d, lo:%d, ans: %d\n",
		// 	i, hi, lo, ans)
	}
	return ans
}

func main() {
	A := []int{1, 3, 6}
	K := 3
	fmt.Printf("%d\n", smallestRangeII(A, K))
}
