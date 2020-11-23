/* Copyright (C) 2020 by iamslash */

package main

import (
  "fmt"
  "math"
  "sort"
)

// 48ms 100.00% 6.5MB 100.00%
// binary search
// O(NlgN) O(1)
func lowerBound(A []int, k int) int {
  l, m, h := 0, 0, len(A) - 1
  for l < h {
    m = l + (h - l) / 2
    if A[m] < k {
      l = m + 1
    } else {
      h = m
    }
  }
  return l
}
func max(a int, b int) int {
  if a > b {
    return a
  }
  return b
}
func min(a int, b int) int {
  if a > b {
    return b
  }
  return a
}
func findRadius(houses []int, heaters []int) int {
  sort.Ints(heaters)
  minRadius := math.MinInt32
  for _, house := range houses {
    idxLarger := lowerBound(heaters, house)
    curRadius := math.MaxInt32
    if heaters[idxLarger] < house {
      curRadius = house - heaters[idxLarger]
    } else {
      curRadius = heaters[idxLarger] - house
    }
    if idxLarger > 0 && heaters[idxLarger] >= house {
      curRadius = min(curRadius, house - heaters[idxLarger-1])
    }    
    minRadius = max(minRadius, curRadius)
  }
  return minRadius
}

// houses: 1 5 
// heater: 2      

func main() {
  fmt.Println(lowerBound([]int{2}, 1))
}
