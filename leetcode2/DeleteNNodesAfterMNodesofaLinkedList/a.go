/* Copyright (C) 2020 by iamslash */

package main

import "fmt"


// b
//   p
// - 1 2 3 4 5 6 7 8 9 10 11 12 13
//   2
//   3

// 12ms 100.00% 5.8MB 100.00%
// linked list
// O(N) O(1)
func deleteNodes(h *ListNode, m int, n int) *ListNode {
  b := &ListNode{Val:0, Next:h}
  p := h
  for p != nil {
    i := 0
    for p != nil && i < m {
      b = p
      p = p.Next
      b.Next = p
      i++
    }
    i = 0
    for p != nil && i < n {
      p = p.Next
      b.Next = p
      i++
    }    
  }
  return h
}
