/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 48ms 98.40% 28.5MB 35.71%
// O(N) O(N)
class Solution {
 private:
  int m_maxlen = 0;
  int dfs(TreeNode* u) {
    // base
    if (u == NULL)
      return 0;
    // recursion
    int l = dfs(u->left) + 1;
    int r = dfs(u->right) + 1;
    if (u->left && u->val + 1 != u->left->val)
      l = 1;
    if (u->right && u->val + 1 != u->right->val)
      r = 1;
    int len = std::max(l, r);
    m_maxlen = std::max(m_maxlen, len);
    return len;
  }
 public:
  int longestConsecutive(TreeNode* u) {
    dfs(u);
    return m_maxlen;
  }
};

int main() {
  // TreeNode* u = new TreeNode(
  //     1,
  //     NULL,
  //     new TreeNode(
  //         3,
  //         new TreeNode(2),
  //         new TreeNode(
  //             4,
  //             NULL,
  //             new TreeNode(5))));
  // TreeNode* u = new TreeNode(
  //     3,
  //     new TreeNode(2),
  //     new TreeNode(
  //         4,
  //         NULL,
  //         new TreeNode(5)));
  // TreeNode* u = new TreeNode(3, new TreeNode(2), new TreeNode(4));
  // TreeNode* u = new TreeNode(3, new TreeNode(2), NULL);
  TreeNode* u = new TreeNode(2, new TreeNode(3), NULL);
  Solution sln;
  printf("%d\n", sln.longestConsecutive(u));
  
  return 0;
}
