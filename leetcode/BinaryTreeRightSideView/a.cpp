// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> rslt;
    if (root == NULL)
      return rslt;
    // BFS
    std::queue<std::pair<TreeNode*, int>> Q;
    Q.push(std::make_pair(root, 0));
    while (!Q.empty()) {
      TreeNode* q_tn = Q.front().first;
      int       q_lv = Q.front().second;
      Q.pop();
      if (Q.empty() || q_lv < Q.front().second)
        rslt.push_back(q_tn->val);
      if (q_tn->left)
        Q.push(std::make_pair(q_tn->left, q_lv+1));
      if (q_tn->right)
        Q.push(std::make_pair(q_tn->right, q_lv+1));
    }
    return rslt;
  }
};

int main() {
  TreeNode* t = new TreeNode(1,
                             new TreeNode(2, NULL,
                                          new TreeNode(5)),
                             new TreeNode(3, NULL,
                                          new TreeNode(4)));
  Solution sln;
  auto rslt = sln.rightSideView(t);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
