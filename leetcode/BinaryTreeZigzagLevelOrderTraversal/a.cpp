/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
  std::vector<std::vector<int>> r;
  void _traverse(TreeNode* node, int lv) {
    // base condition
    if (node == NULL)
      return;
    // printf("%d %d\n", node->val, lv);
    
    if (r.size() == lv - 1) {
      r.push_back(std::vector<int>());
    }
    r[lv-1].push_back(node->val);

    // recursion
    if (node->left)
      _traverse(node->left, lv+1);
    if (node->right)
      _traverse(node->right, lv+1);          
  }
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    _traverse(root, 1);
    for (int i = 0; i < r.size(); ++i) {
      if (i % 2 == 1)
        std::reverse(r[i].begin(), r[i].end());
    }
    return r;
  }
};


  //   3
  //  / \
  // 9  20
  //   /  \
  //  15   7
    
int main() {
  TreeNode* p = new TreeNode(3,
                             new TreeNode(9, NULL, NULL),
                             new TreeNode(20,
                                          new TreeNode(15, NULL, NULL),
                                          new TreeNode(7, NULL, NULL)));  
  Solution s;
  std::vector<std::vector<int>> r = s.zigzagLevelOrder(p);
  for (const auto& y : r) {
    for (int x : y) {
      printf("%d ", x);
    }
    printf("\n");
  }
  
  return 0;
}
