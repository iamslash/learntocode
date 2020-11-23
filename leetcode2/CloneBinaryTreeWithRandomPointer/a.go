/* Copyright (C) 2020 by iamslash */

package main

// 84ms 100.00% 6.9MB 100.00%
// DFS
// O(N) O(N)
func dfs(u *Node, nodeMap map[*Node]*NodeCopy) *NodeCopy {
	// base
	if u == nil {
		return nil
	}
	if nodeMap[u] != nil {
		return nodeMap[u]
	}
	// recursion
	v := &NodeCopy{
		Val: u.Val,
	}
	nodeMap[u] = v
	v.Left = dfs(u.Left, nodeMap)
	v.Right = dfs(u.Right, nodeMap)
	v.Random = dfs(u.Random, nodeMap)
	return v
}
func copyRandomBinaryTree(u *Node) *NodeCopy {
	nodeMap := make(map[*Node]*NodeCopy)
	return dfs(u, nodeMap)
}
