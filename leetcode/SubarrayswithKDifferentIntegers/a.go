/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// 80ms 73.33% 7.6MB 100.00%
// hash map, sliding window
// O(N) O(N)
func cntWithMostK(A []int, K int) int {
  n, ans, i, j := len(A), 0, 0, 0
  cnt := make(map[int]int)
  for j = 0; j < n; j++ {
    if cnt[A[j]] == 0 {
      K--
    }
    cnt[A[j]]++
    for K < 0 {
      cnt[A[i]]--
      if cnt[A[i]] == 0 {
        K++
      }
      i++
    }
    ans += j - i + 1
  }
  return ans
}
func subarraysWithKDistinct(A []int, K int) int {
  return cntWithMostK(A, K) - cntWithMostK(A, K-1);
}

func main() {
  A := []int{1, 2, 1, 2, 3}
  K := 2
  fmt.Println(subarraysWithKDistinct(A, K))
}
