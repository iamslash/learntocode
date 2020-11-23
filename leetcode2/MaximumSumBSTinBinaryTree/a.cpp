/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

// 424ms 29.05% 219.9MB 16.08%
// post order
// O(N) O(lgN)
class Solution {
 private:
  int maxSum = 0;
  vector<int> dfsPost(TreeNode* u) {
    // base
    if (!u) {
      return {INT_MAX, INT_MIN, 0};
    }    
    // recursion
    auto left = dfsPost(u->left);
    auto right = dfsPost(u->right);
    // Check it is BST
    if ((left.size() && right.size() &&
         u->val > left[1] &&
         u->val < right[0]) == false) {
      return {};
    }
    int sum = u->val + left[2] + right[2];
    maxSum = max(maxSum, sum);
    int minNum = min(u->val, left[0]);
    int maxNum = max(u->val, right[1]);
    return {minNum, maxNum, sum};
  }
 public:
  int maxSumBST(TreeNode* u) {
    dfsPost(u);
    return maxSum;
  }
};
