// Copyright (C) 2023 by iamslash

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

//      3
//    /   \
//   1     4
//  / \   /
// 0   2 2

// 3ms 89.12% 41.7MB 56.25%
// hash map
// O(NlgN) O(N)
class Solution {
    private void dfs(TreeMap<Integer, TreeMap<Integer, List<Integer>>> vertMap, TreeNode u, int row, int col) {
        // base
        if (u == null) {
            return;
        }
        // recursion
        vertMap.putIfAbsent(col, new TreeMap<>());
        vertMap.get(col).putIfAbsent(row, new ArrayList<>());
        vertMap.get(col).get(row).add(u.val);
        dfs(vertMap, u.left, row + 1, col - 1);
        dfs(vertMap, u.right, row + 1, col + 1);
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, List<Integer>>> vertMap = new TreeMap<>();
        dfs(vertMap, root, 0, 0);
        List<List<Integer>> ans = new ArrayList<>();
        for (TreeMap<Integer, List<Integer>> colMap : vertMap.values()) {
            List<Integer> numList = new ArrayList<>();
            for (List<Integer> rowSet : colMap.values()) {
                Collections.sort(rowSet);
                for (int num : rowSet) {
                    numList.add(num);
                }
            }
            ans.add(numList);
        }
        return ans;
    }
}
