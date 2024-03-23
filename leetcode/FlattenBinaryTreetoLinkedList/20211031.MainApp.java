// 0ms 100.00% 38.5MB 61.54%
// DFS
// O(N) O(lgN)
class Solution {
    // Return right terminal node
    private TreeNode dfs(TreeNode u) {
        // base
        if (u.left == null && u.right == null) {
            return u;
        }
        if (u.left != null) {
            TreeNode t = u.right;
            u.right = u.left;
            u.left = t;
        }
        // recursion
        TreeNode leftTerm = dfs(u.right);
        if (u.left != null && leftTerm != null) {
            TreeNode rightTerm = dfs(u.left);
            leftTerm.right = u.left;
            u.left = null;
            leftTerm = rightTerm;
        }
        return leftTerm;
    }
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root);
    }
}
