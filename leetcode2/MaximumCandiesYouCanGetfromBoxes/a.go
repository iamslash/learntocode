/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 124ms 50.00% 7.7MB 50.00%
// BFS
// O(N) O(N)
func maxCandies(status []int, candies []int,
  keys [][]int, containedBoxes [][]int, initialBoxes []int) int {
  queue := []int{}
  todo := make(map[int]bool)
  ans := 0
  for _, box := range initialBoxes {
    if status[box] == 1 {
      queue = append(queue, box)
    } else {
      todo[box] = true
    }
  }
    
  for len(queue) > 0 {
    u := queue[0]
    queue = queue[1:]
    ans += candies[u]
    for _, key := range keys[u] {
      status[key] = 1
    }
    for _, box := range containedBoxes[u] {
      todo[box] = true
    }
    for k, _ := range todo {
      if status[k] == 1 {
        queue = append(queue, k)
        delete(todo, k)
      }
    }
  }
  return ans
}
