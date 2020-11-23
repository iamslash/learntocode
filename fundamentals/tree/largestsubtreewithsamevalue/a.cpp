/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int a) : val(a), left(NULL), right(NULL) {}
};

class Solution {
 private:
  int m_max = 0;
 public:
  int dfs(TreeNode* u, TreeNode* p) {
    // base
    if (!u)
      return 0;

    // recursion
    int l = dfs(u->left, u);
    int r = dfs(u->right, u);
    int s = l + r + 1;
    m_max = std::max(m_max, s);
    if (!p || u->val != p->val)
      return 0;
    return s;
  }
  int solve(TreeNode* u) {
    dfs(u, NULL);
    return m_max;
  }
};

int main() {
  TreeNode* h = new TreeNode(0);

  h->left = new TreeNode(1);
  h->left->left = new TreeNode(1);
  h->left->right = new TreeNode(1);

  h->right = new TreeNode(1);
  h->right->left = new TreeNode(2);
  h->right->right = new TreeNode(3);

  Solution sln;
  
  printf("%d\n", sln.solve(h));
      
  return 0;
}
