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

//        3
//       / \
//      9   20
//        /    \
//      15      7 

// 1ms 87.84% 43MB 13.89%
// BFS, deque
// O(N) O(N)
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Deque<TreeNode> deq = new ArrayDeque<>();
        deq.offerFirst(root);
        int lvl = 0;
        while (!deq.isEmpty()) {
            ans.add(new ArrayList<>());
            int n = deq.size();
            for (int i = 0; i < n; ++i) {
                TreeNode u = lvl % 2 == 0 ? deq.pollFirst() : deq.pollLast();
                ans.get(lvl).add(u.val);
                if (lvl % 2 == 0) {
                    if (u.left != null) {
                        deq.offerLast(u.left);
                    }
                    if (u.right != null) {
                        deq.offerLast(u.right);
                    }
                } else {
                    if (u.right != null) {
                        deq.offerFirst(u.right);
                    }
                    if (u.left != null) {
                        deq.offerFirst(u.left);
                    }
                }
            }
            lvl++;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
