/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

func print(h *ListNode) {
  p := h
  for p != nil {
    fmt.Printf("%d ", p.Val)
    p = p.Next
  }
  fmt.Println()
}

//         
//         p
// h : 1 1 2

// 0ms 100.00% 3.2MB 31.25%
func deleteDuplicates(h *ListNode) *ListNode {
  p := h

  for p != nil && p.Next != nil {
    if p.Val == p.Next.Val {
      p.Next = p.Next.Next
      continue
    }
    p = p.Next
  }
  
  return h
}

func main() {
  h := &ListNode{1, &ListNode{1, &ListNode{2, nil}}}
  print(deleteDuplicates(h))  
}
