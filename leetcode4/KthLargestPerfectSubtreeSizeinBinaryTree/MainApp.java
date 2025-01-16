// Copyright (C) 2025 by iamslash

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

// 1576ms 5.57% 45.23MB 53.31%
// dfs
// O(N) O(lgN)
class Solution {
    private int dfs(List<Integer> ans, TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }

        // recursion
        int left = dfs(ans, u.left);
        int right = dfs(ans, u.right);
        if (left == right && left >= 0) {
            System.out.printf("node: %d, left: %d, right: %d\n", u.val, left, right);
            int perfectSubtreeNodeCount = (1 << (left + 1)) - 1; // pow 연산 결과 계산
            ans.add(perfectSubtreeNodeCount); // 직접 ans 에 추가
            return left + 1;
        }

        return -1;
    }
    
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        List<Integer> ans = new ArrayList<>();
        dfs(ans, root);
        Collections.sort(ans);
        System.out.println(ans);

        if (k <= ans.size()) {
            return ans.get(ans.size() - k); // 이미 계산된 값을 사용
        }

        return -1;
    }
}


// Idea: perfect binary tree
//
//        1
//
//        1
//      /   \
//     2     3
//
//        1
//      /   \
//     2     3
//   /  \   /  \
//  4    5 6    7
//
// Design dfs(u):
// - Return values:
//   - -1: u is not a perfect binary tree
//   - lv (>= 0): level (lv) of the perfect binary tree at u
//     where the number of nodes = 2^lv - 1
// - Parameters:
//   - u: the current node being visited
// - Base case:
//   - If u == null, return 0 (the level of an empty tree is 0)
// - Recursive case:
//   - leftLV: level of the left perfect binary subtree
//   - rightLV: level of the right perfect binary subtree
//   - If leftLV == rightLV && leftLV >= 0:
//       - u is a perfect binary tree
//       - Add leftLV + 1 to ans
//       - Return leftLV + 1
//   - Else:
//       - u is not a perfect binary tree
//       - Return -1

// 12ms 51.57% 45.60MB 11.50%
// DFS
// O(N) O(lgN)
class Solution {
    private int dfs(List<Integer> ans, TreeNode u) {
        // base
        if (u == null) {
            return 0;
        }

        // recursion
        int leftLV = dfs(ans, u.left);
        int rightLV = dfs(ans, u.right);
        if (leftLV == rightLV && leftLV >= 0) {
            ans.add(leftLV + 1);
            return leftLV + 1;
        }

        return -1;
    }
    
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        List<Integer> ans = new ArrayList<>();
        dfs(ans, root);
        Collections.sort(ans);

        if (k <= ans.size()) {
            return (1 << ans.get(ans.size() - k)) - 1;
        }

        return -1;
    }
}
