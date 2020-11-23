/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <cstdio>
#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// O(N) O(N)
class BSTIterator {
 public:
  std::stack<TreeNode*> m_stck;
  explicit BSTIterator(TreeNode *t) {
    findsmallestone(t);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return m_stck.empty() ? false : true;
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* t = m_stck.top(); m_stck.pop();
    if (t->right != NULL)
      findsmallestone(t->right);
    return t->val;
  }

  void findsmallestone(TreeNode* t) {
    while (t) {
      m_stck.push(t);
      t = t->left;
    }
  }
};

//          5
//       /     \
//      2       7
//    /   \    / \
//   1     4  6   8
//        / \
//       3
// 5 4 3

int main() {

  TreeNode* root = new TreeNode(1,
                                NULL,
                                new TreeNode(2));
  
  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) {
    // std::cout << i.next();
    printf("%d\n", i.next());
  }
  
  return 0;
}
