/* Copyright (C) 2022 by iamslash */

package main

type Node struct {
    Val int
    Left *Node
    Right *Node
}

// 3ms 42.74% 3MB 96.77%
// in-order, dummy node, prev node
// O(N) O(lgN)
var prev *Node = nil

func dfs(u *Node) {
    // base
    if u == nil {
        return
    }
    // recursion
    dfs(u.Left)
    prev.Right = u
    u.Left = prev
    prev = u
    dfs(u.Right)    
}

func treeToDoublyList(root *Node) *Node {
    if root == nil {
        return nil
    }
    dumm := &Node{Right: root}
    prev = dumm
    dfs(root)
    head := dumm.Right
    head.Left = prev
    prev.Right = head
    return head
}

func main() {
}
