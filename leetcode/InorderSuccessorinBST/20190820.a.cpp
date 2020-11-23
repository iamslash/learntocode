/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}      
};

// 40ms 98.85% 26.4MB 16.61%
// recursive way
// O(lgN) O(1)
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* u, TreeNode* p) {
    // base
    if (u == NULL)
      return NULL;

    // recursion
    if (u->val <= p->val) {
      return inorderSuccessor(u->right, p);
    }
    TreeNode* l = inorderSuccessor(u->left, p);    
    return l != NULL ? l : u;
  }
};

int main() {
  // TreeNode* p = new TreeNode(1);
  // TreeNode* u = new TreeNode(2,
  //                            p,
  //                            new TreeNode(3));
  TreeNode* u = new TreeNode(
      5,
      new TreeNode(3, new TreeNode(2, new TreeNode(1), NULL), new TreeNode(4)),
      new TreeNode(6));
  TreeNode* p = u;
  Solution sln;
  u = sln.inorderSuccessor(u, p);
  if (u == NULL)
    printf("NULL\n");
  else
    printf("%d\n", u->val);
  
  return 0;
}
