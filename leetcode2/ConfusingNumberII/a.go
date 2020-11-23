/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 428ms 61.11% 2MB 100.00% 
// dfs
// O(N) O(lg_10_N)
var ans int
func validNum(numMap map[int]int, n int64) bool {
  src, dst := n, int64(0)
  for n > 0 {
    dst = dst * 10 + int64(numMap[int(n) % 10])
    n /= 10
  }
  return src != dst
}
func dfs(numMap map[int]int, N, i int64) {
  // base
  if i > 0 && validNum(numMap, i) {
    ans++
  }
  // recursion
  for key := range numMap {
    num := i * 10 + int64(key);
    if num <= N && num > 0 {
      dfs(numMap, N, num)
    }
  }
}
func confusingNumberII(N int) int {
  numMap := make(map[int]int)
  numMap[0] = 0
  numMap[1] = 1
  numMap[6] = 9
  numMap[8] = 8
  numMap[9] = 6
  ans = 0
  dfs(numMap, int64(N), 0)
  return ans
}
