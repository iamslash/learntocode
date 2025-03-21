// Copyright (C) 2024 by iamslash

import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// Idea: bst dfs
//
// - Define last
// - Define head
// - Traverse BST in-order
// - Update head.right.left = last
// - Update last.right = head.right
// - Return head.right

// 0ms 100.00% 42.3MB 7.99%
// dfs
// O(N) O(lgN)
class Solution {
    private Node last;

    private void dfs(Node u) {
        if (u == null) {
            return;
        }

        dfs(u.left);
        last.right = u;
        u.left = last;
        last = u;
        dfs(u.right);
    }
    
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return root;
        }

        Node head = new Node();
        last = head;
        dfs(root);
        head.right.left = last;
        last.right = head.right;

        return head.right;
    }
}
