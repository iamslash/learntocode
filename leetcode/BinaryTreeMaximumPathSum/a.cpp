/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/845/

#include <cstdio>
#include <algorithm>
#include <limits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};


//   -2
//   /
// -1
//
class Solution {
 public:
  int solve(TreeNode* t, int& maxv) {
    // base condition
    if (t == NULL)
      return 0;
    int lv = std::max(0, solve(t->left, maxv));
    int rv = std::max(0, solve(t->right, maxv));
    maxv = std::max(maxv, lv + rv + t->val);
    return t->val += std::max(lv, rv);
  }
  int maxPathSum(TreeNode* t) {
    int maxv = sztd::numeric_limits<int>::min();
    solve(t, maxv);
    return maxv;
  }
};

int main() {

  // TreeNode* t = new TreeNode(-10,
  //                            new TreeNode(9),
  //                            new TreeNode(20,
  //                                         new TreeNode(15),
  //                                         new TreeNode(7)));
  // TreeNode* t = new TreeNode(-3);
  TreeNode* t = new TreeNode(-2,
                             new TreeNode(-1),
                             NULL);

  Solution sln;
  printf("%d\n", sln.maxPathSum(t));
  
  return 0;
}
