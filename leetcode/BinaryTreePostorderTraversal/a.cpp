/* Copyright (C) 2019 by iamslash */

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

//    1
//   / \
//  a   b
//
// s:
// 0ms 100.00%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    if (root == NULL)
      return {};
    std::vector<int> rslt;
    std::stack<TreeNode*> stck;
    stck.push(root);
    while (!stck.empty()) {
      TreeNode* u = stck.top(); stck.pop();
      if (u->left == NULL && u->right == NULL) {
        rslt.push_back(u->val);
        continue;
      }
      stck.push(u);
      if (u->right) {
        stck.push(u->right);
        u->right = NULL;
      }
      if (u->left) {
        stck.push(u->left);
        u->left = NULL;
      }
    }
    return rslt;
  }
};
//   1
//  / \
// 2   3
//    / \
//   4   5
//
// 5 4 3 2 1
//
//    3
//   / \
//  1   2
// 1 2 3
int main() {
  // TreeNode* root = new TreeNode(1,
  //                               new TreeNode(2),
  //                               new TreeNode(3,
  //                                            new TreeNode(4),
  //                                            new TreeNode(5)));
  TreeNode* root = new TreeNode(3,
                                new TreeNode(1),
                                new TreeNode(2));
  Solution sln;
  auto r = sln.postorderTraversal(root);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
