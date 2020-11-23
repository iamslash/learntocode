/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

// b  p
// 0->1->2->6->3->4->5->6

// 4ms 100.00% 4.6MB 40.00%
// incremental method
// O(1) O(1)
func removeElements(head *ListNode, val int) *ListNode {
	dumb := &ListNode{0, head}
	p := head
	b := dumb

	for p != nil {
		if p.Val != val {
			b = p
		} else {
			b.Next = p.Next
		}
		p = p.Next
	}

	return dumb.Next
}

func main() {
	fmt.Println("hello world")
}
