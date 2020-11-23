/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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
  std::vector<TreeNode*> gen(int fr, int to) {
    std::vector<TreeNode*> rtrn;
    if (to == fr)
      rtrn.push_back(new TreeNode(fr));
    if (to < fr)
      rtrn.push_back(NULL);
    if (to > fr) {
      for (int i = fr; i <= to; ++i) {
        std::vector<TreeNode*> l = gen(fr, i - 1);
        std::vector<TreeNode*> r = gen(i + 1, to);
        for (int j = 0; j < l.size(); ++j) {
          for (int k = 0; k < r.size(); ++k) {
            TreeNode * t = new TreeNode(i);
            t->left = l[j];
            t->right = r[k];
            rtrn.push_back(t);
          }
        }
      }
    }
    return rtrn;
  }
  std::vector<TreeNode*> generateTrees(int n) {
    return n > 0 ? gen(1, n) : std::vector<TreeNode*>();
  }
};

void printt(TreeNode* t) {
  if (t) {
    printf("%d ", t->val);
    printt(t->left);
    printt(t->right);
  } else {
    printf("null ");
  }
}

int main() {
  int n = 3;
  
  Solution s;
  auto r = s.generateTrees(n);
  for (TreeNode* t : r) {
    printt(t);
    printf("\n");
  }
  
  return 0;
}
