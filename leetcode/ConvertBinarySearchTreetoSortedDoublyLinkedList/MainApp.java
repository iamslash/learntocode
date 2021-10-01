// Copyright (C) 2021 by iamslash

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

// 0ms 100.00% 38.1MB 90.56%
// keywords: dummy node, prev node
// in-order traverse
// O(N) O(lgN)
class Solution {
    private Node prv;
    // in-order traverse
    private void dfs(Node u) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        dfs(u.left);
        prv.right = u;
        u.left = prv;
        prv = u;        
        dfs(u.right);
    }
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        Node dum = new Node();
        prv = dum;
        dfs(root);
        // prv is tail
        // dum.rigth is head
        prv.right = dum.right;
        dum.right.left = prv;
        return dum.right;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
