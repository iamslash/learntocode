/* Copyright (C) 2020 by iamslash */

package main

// 4ms 100.00% 5.9MB 100.00%
func cloneTree(u *Node) *Node {
	// base
	if u == nil {
		return nil
	}
	s := &Node{
		Val, u.Val,
	}
	for _, v := range u.Children {
		s.Children = append(s.Children, cloneTree(v))
	}
	return s
}
