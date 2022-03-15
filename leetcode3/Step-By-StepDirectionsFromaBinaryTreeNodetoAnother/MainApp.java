// Copyright (C) 2022 by iamslash

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

// LL LR
// 

// 30ms .92% 105.5MB 63.55%
// dfs
// O(N) O(lgN)
class Solution {
    private boolean dfs(TreeNode u, int val, StringBuilder path) {
        // base
        if (u.val == val) {
            return true;
        }
        if (u.left != null && dfs(u.left, val, path)) {
            path.append('L');
        } else if (u.right != null && dfs(u.right, val, path)) {
            path.append('R');
        }
        return path.length() > 0;
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder srcPath = new StringBuilder();
        StringBuilder dstPath = new StringBuilder();
        dfs(root, startValue, srcPath);
        dfs(root, destValue, dstPath);
        int i = 0, bndI = Math.min(srcPath.length(), dstPath.length());
        while (i < bndI && srcPath.charAt(srcPath.length()-1-i) ==
               dstPath.charAt(dstPath.length()-1-i)) {
            ++i;
        }
        StringBuilder ans = new StringBuilder();
        for (int j = i; j < srcPath.length(); ++j) {
            ans.append('U');
        }
        ans.append(dstPath.reverse().substring(i));
        return ans.toString();
    }
}
 
// 29ms 81.35% 104.9MB 66.70%
// dfs, lca
// O(N) O(lgN)
class Solution {
    private TreeNode getLCA(TreeNode u, int a, int b) {
        // base
        if (u == null || u.val == a || u.val == b) {
            return u;
        }
        // recursion
        TreeNode l = getLCA(u.left, a, b);
        TreeNode r = getLCA(u.right, a, b);
        if (l == null) {
            return r;
        }
        if (r == null) {
            return l;
        }
        return u;
    }
    private boolean addPath(TreeNode u, int val, boolean isStart, StringBuilder ans) {
        // base
        if (u == null) {
            return false;
        }
        if (u.val == val) {
            return true;
        }
        // recursion
        ans.append(isStart ? 'U' : 'L');
        if (addPath(u.left, val, isStart, ans)) {
            return true;
        }
        ans.setLength(ans.length()-1);
        ans.append(isStart ? 'U' : 'R');
        if (addPath(u.right, val, isStart, ans)) {
            return true;
        }
        ans.setLength(ans.length()-1);
        return false;
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode lca = getLCA(root, startValue, destValue);
        StringBuilder ans = new StringBuilder();
        addPath(lca, startValue, true, ans);
        addPath(lca, destValue, false, ans);
        return ans.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
