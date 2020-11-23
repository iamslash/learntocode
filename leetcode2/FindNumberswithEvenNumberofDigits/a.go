/* Copyright (C) 2020 by iamslash */

package main

// 4ms 90.05% 3.1MB 100.00%
// modulation
// O(N) O(1)
func even(n int) bool {
    // fmt.Printf("%d", n)
  ans := 0
  for n > 0 {
    ans++
    n /= 10
  }
    // fmt.Printf(" %d\n", ans)
  return ans & 1 == 0
}

func findNumbers(A []int) int {
  ans := 0
  for _, a := range A {
    if even(a) {
      ans++
    }
  }
  return ans
}
