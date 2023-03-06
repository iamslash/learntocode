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

// 48ms 37.01% 60.5MB 71.48%
// bfs, sort
// O(NlgN) O(N)
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        List<Long> sumList = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            long sum = 0;
            // System.out.printf("size: %d\n", size);
            // System.out.println(q);
            while (size-- > 0) {
                TreeNode u = q.poll();
                sum += u.val;
                if (u.left != null) {
                    q.offer(u.left);
                }
                if (u.right != null) {
                    q.offer(u.right);
                }
            }
            sumList.add(sum);
            // System.out.println(sumList);
        }
        if (sumList.size() < k) {
            return -1;
        }        
        Collections.sort(sumList, (a, b) -> -Long.compare(a, b));
        return sumList.get(k-1);
    }
}
