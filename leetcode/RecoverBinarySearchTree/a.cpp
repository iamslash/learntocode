/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <limits>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

 //   1
 //  /
 // 3
 //  \
 //   2
// a: 3
// b: 1
// p: 1
//
// wrong: 3 2 1
// right: 1 2 3

// in-order traversal
// 52ms 99.19% 28.7MB 100.00%
// O(N) O(1)
class Solution {
 private:
  TreeNode* m_root_a = NULL;  // first wrong node
  TreeNode* m_root_b = NULL;  // second wrong node
  TreeNode* m_root_p = NULL;  // prev node
  void solve(TreeNode* root) {
    if (root == NULL)
      return;
    //
    solve(root->left);
    //
    if (m_root_a == NULL && m_root_p->val >= root->val) {
      m_root_a = m_root_p;
    }
    if (m_root_a != NULL && m_root_p->val >= root->val)
      m_root_b = root;
    m_root_p = root;
    //
    solve(root->right);
  }
 public:
  void recoverTree(TreeNode* root) {
    m_root_p = new TreeNode(std::numeric_limits<int>::min());
    solve(root);
    std::swap(m_root_a->val, m_root_b->val);
  }
};

void printt(TreeNode* root) {
  if (root == NULL) {
    // printf("N ");
    return;
  }
  printf("%d ", root->val);
  printt(root->left);
  printt(root->right);
}

int main() {
  TreeNode* root = new TreeNode(1, new TreeNode(3, NULL, new TreeNode(2)), NULL);
  Solution sln;
  sln.recoverTree(root);
  printt(root);
  
  return 0;
}
