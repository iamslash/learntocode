/* Copyright (C) 2020 by iamslash */

package main

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

// Find a root of tree
// root's value = (sum of values) - (sum of values without root)
// node's value is unique

// 28ms 50.00% 17.9MB 10.00%
// O(N) O(1)
func findRoot(tree []*Node) *Node {
	sum, sumChildren := 0, 0
	for _, u := range tree {
		sum += u.Val
		for _, v := range u.Children {
			sumChildren += v.Val
		}
	}
	diff := sum - sumChildren
	for _, u := range tree {
		if u.Val == diff {
			return u
		}
	}
	return nil
}
