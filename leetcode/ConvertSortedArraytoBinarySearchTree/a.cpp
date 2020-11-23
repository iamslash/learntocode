/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    // base condition
    if (nums.size()==0)
      return NULL;

    // extract left, right vector
    const auto mid = nums.begin() + nums.size() / 2;
    std::vector<int> vl(nums.begin(), mid);
    std::vector<int> vr(mid+1, nums.end());

    // recursion
    TreeNode* p = new TreeNode(*mid);
    p->left = sortedArrayToBST(vl);
    p->right = sortedArrayToBST(vr);
    
    return p;
  }
};

int main() {
  return 0;
}
