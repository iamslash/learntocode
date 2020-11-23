/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <limits>
#include <cstdlib>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 16ms 93.34% 21.7MB 100.00%
// inorder
// O(N) O(lgN)
class Solution {
 private:
  int prvVal = -1;
  int minDif = std::numeric_limits<int>::max();
 public:
  void inOrder(TreeNode* u) {
    // base
    if (!u)
      return;
    // recursion
    inOrder(u->left);
    if (prvVal >= 0) {
      int curDif = std::abs(u->val) - std::abs(prvVal);
      minDif = std::min(minDif, curDif);
    }
    prvVal = u->val;       
    inOrder(u->right);
  }
  int getMinimumDifference(TreeNode* u) {
    inOrder(u);
    return minDif;
  }
};
int main() {
  return 0;
}
