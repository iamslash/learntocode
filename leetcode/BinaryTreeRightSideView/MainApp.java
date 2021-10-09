// Copyright (C) 2021 by iamslash

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// 0ms 100.00% 37.7MB 61.75%
// DFS
// O(N) O(lgN)
class Solution {
    private void dfs(List<Integer> ans, TreeNode u, int depth) {
        // base
        if (u == null) {
            return;
        }
        if (depth == ans.size()) {
            ans.add(u.val);
        }
        // recursion
        dfs(ans, u.right, depth+1);
        dfs(ans, u.left, depth+1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        dfs(ans, root, 0);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
