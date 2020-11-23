/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 32ms 55.03% 20.9MB 87.50%
// DFS
// O(N^2) O(lgN)
class Solution {
 private:
  bool dfs(TreeNode* u, TreeNode* v) {
    if (!u)
      return !v;
    if (!v)
      return false;
    return u->val == v->val && dfs(u->left, v->left) && dfs(u->right, v->right);
  }
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s)
      return !t;
    return dfs(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};

int main() {
  return 0;
}
