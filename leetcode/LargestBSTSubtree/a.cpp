/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};


//     10 
//    /  \ 
//   5   15 
//  / \    \ 
// 1   8    7

// 32ms 30.33% 28.9MB 28.21%
// post order traversal
// O(N) O(N)
class Solution {
 private:
  int m_best = 0;
  // return: {min of decendants,
  //          max of decendants,
  //          max BST count}
  std::vector<int> dfs(TreeNode* u) {
    // base
    if (!u)
      return {INT_MAX, INT_MIN, 0};
    auto l = dfs(u->left);
    auto r = dfs(u->right);
    // u is BST
    if (l[1] < u->val && u->val < r[0])
      return {std::min(l[0], u->val),
            std::max(u->val, r[1]),
            l[2] + r[2] + 1};
    // us is not BST
    return {INT_MIN, INT_MAX, std::max(l[2], r[2])};
  }
 public:
  int largestBSTSubtree(TreeNode* u) {
    auto r = dfs(u);
    return r[2];
  }
};


//     2
//    / 
//   3   
//  /
// 1
int main() {

  // TreeNode* u = new TreeNode(10,
  //                            new TreeNode(5, new TreeNode(1), new TreeNode(8)),
  //                            new TreeNode(15, NULL, new TreeNode(7)));
  TreeNode* u = new TreeNode(2, new TreeNode(3, new TreeNode(1), NULL), NULL);
  Solution sln;
  printf("%d\n", sln.largestBSTSubtree(u));
  
  return 0;
}
