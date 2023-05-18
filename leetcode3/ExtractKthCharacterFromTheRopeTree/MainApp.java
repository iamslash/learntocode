// Copyright (C) 2023 by iamslash

import java.util.*;

class RopeTreeNode {
    int len;
    String val;
    RopeTreeNode left;
    RopeTreeNode right;
    RopeTreeNode() {}
    RopeTreeNode(String val) {
        this.len = 0;
        this.val = val;
    }
    RopeTreeNode(int len) {
        this.len = len;
        this.val = "";
    }
    RopeTreeNode(int len, RopeTreeNode left, RopeTreeNode right) {
        this.len = len;
        this.val = "";
        this.left = left;
        this.right = right;
    }
}

// 1ms 100.00% 50.8MB 100.00%
// in-order traversal
// O(N) O(lgN)
class Solution {
    private void dfs(StringBuilder sb, RopeTreeNode u) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        dfs(sb, u.left);
        // System.out.printf("u.len: %d, u.val: %s\n", u.len, u.val);
        if (!u.val.isEmpty()) {
            sb.append(u.val);
        }
        dfs(sb, u.right);
    }
    public char getKthCharacter(RopeTreeNode root, int k) {
        StringBuilder sb = new StringBuilder();
        dfs(sb, root);
        return sb.charAt(k-1);
    }
}
