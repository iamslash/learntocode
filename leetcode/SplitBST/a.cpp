/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4ms 100.00% 10.1MB 71.43%
// O(N) O(1)
class Solution {
 public:
  std::vector<TreeNode*> splitBST(TreeNode* u, int n) {
    // base condition
    if (u == NULL)
      return {NULL, NULL};
    if (u->val > n) {
      auto r = splitBST(u->left, n);
      u->left = r[1];
      return {r[0], u};
    }
    auto r = splitBST(u->right, n);
    u->right = r[0];
    return {u, r[1]};
  }
};

int main() {
  return 0;
}
