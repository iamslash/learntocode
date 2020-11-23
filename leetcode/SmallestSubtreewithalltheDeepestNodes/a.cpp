/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 0ms 100%
class Solution {
 private:
  std::pair<int, TreeNode*> solve(TreeNode* root) {

    // printf("%d\n", root ? root->val : -1);
    
    // base
    if (root == NULL) {
      return {0, NULL};
    }

    // recursion
    auto l = solve(root->left);
    auto r = solve(root->right);
    int dl       = l.first;
    TreeNode* pl = l.second;
    int dr       = r.first;
    TreeNode* pr = r.second;

    std::pair<int, TreeNode*> rslt = {
      std::max(dl, dr) + 1,
      dl == dr ? root : dl > dr ? pl : pr
    };
    return rslt;
  }
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return solve(root).second;
  }
};

void printt(TreeNode* t) {
  if (t == NULL)
    return;
  printf("%d ", t->val);
  printt(t->left);
  printt(t->right);
}

int main() {
  TreeNode* t = new TreeNode(3,
                             new TreeNode(5,
                                          new TreeNode(6),
                                          new TreeNode(2,
                                                       new TreeNode(7),
                                                       new TreeNode(4))),
                             new TreeNode(1,
                                          new TreeNode(0),
                                          new TreeNode(8)));
  // TreeNode* t = new TreeNode(1);
  Solution sln;
  printt(sln.subtreeWithAllDeepest(t));
  printf("\n");
  return 0;
}
