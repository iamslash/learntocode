/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 20ms 99.59% 20MB 100.00%
// left boundary, leaves, right boundary
// O(N) O(N)
class Solution {
 private:
  std::vector<int> m_rslt;

  void leftbnd(TreeNode* u) {
    if (!u || (!u->left && !u->right))
      return;
    m_rslt.push_back(u->val);
    leftbnd(u->left ? u->left : u->right);
  }
  void rightbnd(TreeNode* u) {
    if (!u || (!u->left && !u->right))
      return;
    rightbnd(u->right ? u->right : u->left);
    m_rslt.push_back(u->val);
  }
  void leaves(TreeNode* u) {
    if (u == NULL)
      return;
    if (!u->left && !u->right) {
      m_rslt.push_back(u->val);
      return;
    }
    leaves(u->left);
    leaves(u->right);
  }
 public:
  std::vector<int> boundaryOfBinaryTree(TreeNode* u) {
    if (!u)
      return {};
    
    m_rslt.push_back(u->val);
    leftbnd(u->left);
    leaves(u->left);
    leaves(u->right);
    rightbnd(u->right);

    return m_rslt;
  }
};

int main() {
  TreeNode* u = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), new TreeNode(4)));
  Solution sln;
  auto r = sln.boundaryOfBinaryTree(u);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
