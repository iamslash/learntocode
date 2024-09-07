// Copyright (C) 2024 by iamslash

import java.util.*;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// Idea: double dfs
//
// dfsBeforeTarget: dfs before finding target node
// - return: distance from u to target else -1
// dfsAfterTarget: dfs after finding target node
//
//              3
//           /     \
//          ⑤       ➊
//       /  |       |  \
//     6    2       0   8
//        /   \
//       ➐     ➍ 
//

// 12ms 89.78% 42.1MB 87.99%
// double dfs
// O(N) O(lgN)
class Solution {

    private void dfsAfterTarget(List<Integer> ans, int k, TreeNode u, int dist) {
        // base
        if (u == null) {
            return;
        }
        if (k == dist) {
            ans.add(u.val);
        }

        // recursion
        dfsAfterTarget(ans, k, u.left, dist + 1);
        dfsAfterTarget(ans, k, u.right, dist + 1);
    }

    private int dfsBeforeTarget(List<Integer> ans, TreeNode tgt, int k, TreeNode u) {
        // base
        if (u == null) {
            return -1;
        }
        if (u == tgt) {
            dfsAfterTarget(ans, k, u, 0);
            return 1;
        }
        
        // recursion
        int left = dfsBeforeTarget(ans, tgt, k, u.left);
        int right = dfsBeforeTarget(ans, tgt, k, u.right);

        if (left != -1) {
            if (left == k) {
                ans.add(u.val);
            }
            dfsAfterTarget(ans, k, u.right, left + 1);
            return left + 1;
        }
        if (right != -1) {
            if (right == k) {
                ans.add(u.val);
            }
            dfsAfterTarget(ans, k, u.left, right + 1);
            return right + 1;
        }

        return -1;
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> ans = new ArrayList<>(); 
        dfsBeforeTarget(ans, target, k, root);
        return ans;
    }
}
