// Copyright (C) 2022 by iamslash

import java.util.*;

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

// 0ms 100.00% 41.9MB 78.08%
// in-order traversal, dummy node, prev node
// O(N) O(lgN)
class Solution {
    private Node prev;
    private void dfs(Node u) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        dfs(u.left);
        prev.right = u;
        u.left = prev;
        prev = u;
        dfs(u.right);
    }
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return root;
        }
        Node dumm = new Node();
        prev = dumm;
        dfs(root);
        dumm.right.left = prev;
        prev.right = dumm.right;
        return dumm.right;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
