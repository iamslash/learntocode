/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>


    //     1
    //    / \
    //   2   3
    //  /   / \
    // 4   2   4
    //    /
    //   4
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 64ms 90.70% 43.7MB 100.00%
// O(N) O(N)
class Solution {
 private:
  std::unordered_map<std::string, int> m_ump;
  std::vector<TreeNode*> m_rslt;
  std::string solve(TreeNode* root) {
    // base
    if (root == NULL)
      return "";

    // recursion
    std::string s = std::to_string(root->val) + "," + solve(root->left) + "," + solve(root->right);
    if (m_ump[s]++ == 1)
      m_rslt.push_back(root);
    return s;
  }
 public:
  std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    solve(root);
    return m_rslt;
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

  Solution sln;
  TreeNode* root = new TreeNode(1,
                                new TreeNode(2, new TreeNode(4), NULL),
                                new TreeNode(3,
                                             new TreeNode(2, new TreeNode(4), NULL),
                                             new TreeNode(4)));
  auto l = sln.findDuplicateSubtrees(root);
  for (auto t : l) {
    printt(t);
    printf("\n");
  }
  
  return 0;
}
