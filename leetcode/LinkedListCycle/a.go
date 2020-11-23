/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

//    s
// l: 1 2
//    f

// 4ms 97.83% 3.8MB 100.00%
// tortoise and hare algorithm
// O(N) O(1)
func hasCycle(h *ListNode) bool {
	if h == nil {
		return false
	}
	slow := h
	fast := h.Next
	for slow != nil && fast != nil && fast.Next != nil {
		if slow == fast {
			return true
		}
		slow = slow.Next
		fast = fast.Next.Next
	}
	return false
}

func main() {
	fmt.Println("hello world")
}
