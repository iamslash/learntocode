// Copyright (C) 2024 by iamslash

import java.util.*;

public class TreeNode {
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

// 1ms 99.98% 44.6MB 44.97%
// dfs
// O(N) O(N)
class Solution {
    
    private void dfs(List<List<Integer>> rslt, List<Integer> cand,
                     TreeNode u, int sum) {
        // base
        if (u == null) {
            return;
        }
        
        // recursion
        cand.add(u.val);

        if (u.left == null && u.right == null && sum == u.val) {
            rslt.add(new ArrayList<>(cand));
        } else {
            dfs(rslt, cand, u.left, sum - u.val);
            dfs(rslt, cand, u.right, sum - u.val);            
        }
        
        cand.remove(cand.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> rslt = new ArrayList<>();
        List<Integer> cand = new ArrayList<>();
        dfs(rslt, cand, root, targetSum);
        return rslt;
    }
}
