/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// P: 2
   //       5
   //      / \  
   //     3   6
   //    / \
   //   2   4
   //  /
   // 1

// 32ms 93.08% 25.3MB 100.00%
// recursion
// O(lgN) O(lgN)
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* u, TreeNode* p) {
    // base
    if (!u)
      return NULL;
    
    // recursion
    if (u->val <= p->val)
      return inorderSuccessor(u->right, p);
    TreeNode* l = inorderSuccessor(u->left, p);
    return l == NULL ? u : l;
  }
};

int main() {
  return 0;
}
