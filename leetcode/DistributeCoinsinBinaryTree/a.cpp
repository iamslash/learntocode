/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <cmath>
#include <cstdlib>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 8ms 70.93% 13MB 75.09%
// dfs
// O(V+E) O(1)
class Solution {
 private:
  int m_ans = 0;
  int dfs(TreeNode* u) {
    // base
    if (!u)
      return 0;

    // recursion
    int l = dfs(u->left), r = dfs(u->right);
    m_ans += std::abs(l) + std::abs(r);
    return u->val + l + r - 1;
  }
 public:
  int distributeCoins(TreeNode* root) {
    dfs(root);
    return m_ans;
  }
};

int main() {
  return 0;
}
