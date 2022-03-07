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

// 162ms 20.00% 118.9MB 20.00%
// hash map
// O(N) O(N)
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> treeMap = new HashMap<>();
        Set<TreeNode> childSet = new HashSet<>();
        for (int[] item : descriptions) {
            int parentVal = item[0];
            int childVal = item[1];
            treeMap.putIfAbsent(parentVal, new TreeNode(parentVal));
            treeMap.putIfAbsent(childVal, new TreeNode(childVal));
            TreeNode parentNode = treeMap.get(parentVal);
            TreeNode childNode = treeMap.get(childVal);
            childSet.add(childNode);
            if (item[2] == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
        }
        TreeNode rootNode = null;
        for (Integer val : treeMap.keySet()) {
            if (!childSet.contains(treeMap.get(val))) {
                rootNode = treeMap.get(val);
                break;
            }
        }
        return rootNode;
    }
}
