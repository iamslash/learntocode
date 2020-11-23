/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

class Solution {
 private:
  std::unordered_map<TreeNode*, int> m_C;  
 public:
  int rob(TreeNode* u) {
    if (m_C.count(u) > 0)
      return m_C[u];
    if (u == NULL) {
      m_C[u] = 0;
    } else {
      m_C[u] = std::max(u->val +
                   (u->left ?
                    rob(u->left->left) + rob(u->left->right) : 0) +
                   (u->right ?
                    rob(u->right->left) + rob(u->right->right) : 0),
                   rob(u->left) + rob(u->right));
    }
    return m_C[u];      
  }
};

int main() {
  TreeNode* t = new TreeNode(3,
                             new TreeNode(2,
                                          new TreeNode(1),
                                          new TreeNode(3)),
                             new TreeNode(5,
                                          NULL,
                                          new TreeNode(1)));                                          
  // TreeNode* t = new TreeNode(3,
  //                            new TreeNode(2,
  //                                         NULL,
  //                                         new TreeNode(3)),
  //                            new TreeNode(3,
  //                                         NULL,
  //                                         new TreeNode(1)));  

  Solution sln;
  printf("%d\n", sln.rob(t));
  
  return 0;
}
