// Copyright (C) 2021 by iamslash


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

// 9ms 77.78% 69.1MB 78.47%
// DFS
// O(N) O(N)
class Solution {
    private int ans = 0;
    private int dfs(TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }
        // recursion
        int lsum = dfs(u.left);
        int rsum = dfs(u.right);
        if (lsum + rsum == u.val) {
            ans++;
        }
        return lsum + rsum + u.val;
    }
    public int equalToDescendants(TreeNode root) {
        dfs(root);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
