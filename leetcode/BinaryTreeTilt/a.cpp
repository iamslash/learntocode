/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 16ms 94.54% 21.5MB 100.00%
// DFS
// O(N) O(lgN)
class Solution {
 private:
  int tilt = 0;
  int dfs(TreeNode* u) {
    // base
    if (!u)
      return 0;
    // recursion
    int l = dfs(u->left);
    int r = dfs(u->right);
    tilt += std::abs(l - r);
    return l + r + u->val;
  }
 public:
  int findTilt(TreeNode* u) {
    dfs(u);
    return tilt;
  }
};

int main() {
  return 0;
}
