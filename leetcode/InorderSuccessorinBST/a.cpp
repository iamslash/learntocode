/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//           5
//        /     \
//      3        6
//    /  \
//   2    4
//  /
// 1
//
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 N

// 32ms 93.33% 25.2MB 100.00%
// O(N) O(lgN)
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* u, TreeNode* p) {
    // base
    if (!u)
      return NULL;
    if (u->val <= p->val)
      return inorderSuccessor(u->right, p);
    TreeNode* l = inorderSuccessor(u->left, p);
    return l == NULL ? u : l;
  }
};

int main() {
  return 0;
}
