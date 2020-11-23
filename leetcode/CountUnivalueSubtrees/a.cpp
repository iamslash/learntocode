/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// What about this???
//
//    5
//   / \
//  7   8
 
// 8ms 100.00% 14.9MB 52.00%
// O(N) O(1)
class Solution {
 private:
  int m_cnt = 0;
  bool isUni(TreeNode* u) {
    // base
    if (!u->left && !u->right) {
      m_cnt++;
      return true;
    }
    
    // recursion
    bool b = true;
    if (u->left)
      b = isUni(u->left) && u->left->val == u->val;
    if (u->right)
      b = isUni(u->right) && b && u->right->val == u->val;
    if (!b)
      return false;
    m_cnt++;
    return b;
  }
 public:
  int countUnivalSubtrees(TreeNode* u) {
    if (!u)
      return 0;
    isUni(u);
    return m_cnt;
  }
};


int main() {
  // TreeNode* u = new TreeNode(5, new TreeNode(1, new TreeNode(5), new TreeNode(5)),
  //     new TreeNode(5, NULL, new TreeNode(5)));
  TreeNode* u = new TreeNode(5,
                             new TreeNode(7),
                             new TreeNode(8));
  Solution sln;
  printf("%d\n", sln.countUnivalSubtrees(u));
  
  return 0;
}
