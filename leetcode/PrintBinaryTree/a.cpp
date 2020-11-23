/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <tuple>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}  
};

   //   1
   //  /
   // 2
// 8ms 100.00% 9.8MB 100.00%
// O(N) O(N)
class Solution {
 private:
  int getDepth(TreeNode* root) {
    if (root == NULL)
      return 0;
    return std::max(getDepth(root->left), getDepth(root->right)) + 1;
  }
 public:
  std::vector<std::vector<std::string>> printTree(TreeNode* root) {
    if (root == NULL)
      return {};
    int h = getDepth(root);
    int w = std::pow(2, h) - 1;
    std::vector<std::vector<std::string>> rslt(h, std::vector<std::string>(w, ""));
    std::queue<std::tuple<TreeNode* , int, int>> q;
    q.push({root, 0, w-1});
    int y = 0;
    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        auto tpl = q.front(); q.pop();
        TreeNode* t = std::get<0>(tpl);
        int beg = std::get<1>(tpl);
        int end = std::get<2>(tpl);
        int x = (beg + end) / 2;
        rslt[y][x] = std::to_string(t->val);
        if (t->left)
          q.push({t->left, beg, x-1});
        if (t->right)
          q.push({t->right, x+1, end});
      }
      ++y;
    }
    return rslt;
  }
};

int main() {
  // TreeNode* root = new TreeNode(1, new TreeNode(2), NULL);
  TreeNode* root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(4)), new TreeNode(3));
  // TreeNode* root = new TreeNode(1, new TreeNode(2), NULL);
  Solution sln;
  auto rslt = sln.printTree(root);
  for (auto& l : rslt) {
    for (auto s : l) {
      printf("[%2s] ", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
