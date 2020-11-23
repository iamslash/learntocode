// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include <cstdio>
#include <vector>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};


//       1
//      / \
//     2   3
//    / \ / \
//   4  5 6  7
//  /
// 8
// O(N) O(N)
// 0ms 100.00%
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> rslt;
    if (root == NULL)
      return rslt;
    std::stack<TreeNode*> stck;
    stck.push(root);
    while (!stck.empty()) {
      TreeNode* t = stck.top(); stck.pop();
      rslt.push_back(t->val);
      if (t->right)
        stck.push(t->right);
      if (t->left)
        stck.push(t->left);
    }
    return rslt;
  }
};

int main() {
  TreeNode* root = new TreeNode(1,
                                NULL,
                                new TreeNode(2,
                                             new TreeNode(3),
                                             NULL));
  Solution sln;
  auto r = sln.preorderTraversal(root);
  for (int a : r) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
