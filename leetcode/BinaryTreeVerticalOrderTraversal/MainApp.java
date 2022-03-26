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

// 3ms 85.77% 41.8MB 94.97%
// hash map, BFS
// O(Nlgn) O(N)
class Pair {
    int order;
    TreeNode node;
    Pair(int order, TreeNode node) {
        this.order = order;
        this.node = node;
    }
}
class Solution {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Map<Integer, List<Integer>> valMap = new TreeMap<>();
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(0, root));
        while (!q.isEmpty()) {
            Pair item = q.poll();
            valMap.putIfAbsent(item.order, new ArrayList<>());
            valMap.get(item.order).add(item.node.val);
            if (item.node.left != null) {
                q.offer(new Pair(item.order - 1, item.node.left));
            }
            if (item.node.right != null) {
                q.offer(new Pair(item.order + 1, item.node.right));
            }
        }
        for (int k : valMap.keySet()) {
            ans.add(valMap.get(k));
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
