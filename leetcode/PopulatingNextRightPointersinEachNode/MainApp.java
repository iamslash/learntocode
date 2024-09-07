// Copyright (C) 2024 by iamslash

import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// 3ms 35.02% 44.1MB 84.90%
// bfs
// O(N) O(lgN)
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        Queue<Node> q = new ArrayDeque<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                Node top = q.poll();
                if (size > 0) {
                    top.next = q.peek();
                }
                if (top.left != null) {
                    q.offer(top.left);
                }
                if (top.right != null) {
                    q.offer(top.right);
                }
            }
        }

        return root;
    }
}

//   []

//         1
//       /   \
//      2     3
//    / |     | \
//   4  5     6  7

// 0ms 100.00% 43.7MB 98.67%
// dfs
// O(N) O(lgN)
class Solution {
    public Node connect(Node u) {
        // base
        if (u == null || u.left == null) {
            return u;
        }
        u.left.next = u.right;
        u.right.next = u.next == null ? null : u.next.left;
        
        // recursion
        connect(u.left);
        connect(u.right);

        return u;
    }
}
