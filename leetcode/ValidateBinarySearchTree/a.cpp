/* Copyright (C) 2018 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

//        10
//       /  
//      5    
//     / \    
//    7   8

// O(N) O(1)
// 4ms 100.00%
#include <iostream>
static int _x = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  bool solve(TreeNode* u, TreeNode* &p) {
    // base condition
    if (u == NULL)
      return true;

    // recursion left
    if (!solve(u->left, p))
      return false;
    // visit root
    if (p != NULL && p->val >= u->val)
      return false;
    p = u;
    // recursion right    
    return solve(u->right, p);
  }
  bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return solve(root, prev);
  } 
};

int main() {
  Solution s;
  // TreeNode* p = new TreeNode(2,
  //                           new TreeNode(1),
  //                           new TreeNode(3));
  // TreeNode* p = new TreeNode(5,
  //                           new TreeNode(1),
  //                            new TreeNode(4,
  //                                         new TreeNode(3),
  //                                         new TreeNode(6)));
  TreeNode* p = new TreeNode(10,
                             new TreeNode(5),
                             new TreeNode(15,
                                          new TreeNode(6),
                                          new TreeNode(20)));
  printf("%s\n", s.isValidBST(p) ? "true" : "false");
  return 0;
}
