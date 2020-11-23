/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

// 0ms 100.00% 2MB 100.00%
// hare and tortoise
// O(N) O(1)
func middleNode(head *ListNode) *ListNode {
	s := head
	f := head
	for f != nil && f.Next != nil {
		s = s.Next
		f = f.Next.Next
	}
	return s
}

func main() {
	fmt.Println("hello world")
}
