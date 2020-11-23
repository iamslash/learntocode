/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/maximum-binary-tree/description/

#include <cstdio>
#include <vector>
#include <algorithm>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* _solve(const std::vector<int>& v, int i, int j) {
    // printf("%d %d\n", i, j);
    // base condition
    if (i == j) 
      return new TreeNode(v[i]);
    else if (i > j)
      return NULL;

    // recursion
    int k = std::max_element(v.begin()+i, v.begin()+j+1) - v.begin();
    TreeNode* r = new TreeNode(v[k]);
    r->left = _solve(v, i, k-1);
    r->right = _solve(v, k+1, j);
    return r;
  }
  TreeNode* constructMaximumBinaryTree(const std::vector<int>& v) {
    if (v.empty())
      return NULL;
    return _solve(v, 0, v.size()-1);
  }
};

int main() {
  std::vector<int> v = {3, 2, 1, 6, 0, 5};
  
  Solution s;
  auto r = s.constructMaximumBinaryTree(v);

  return 0;
}
