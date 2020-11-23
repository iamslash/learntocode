/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <set>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// {-1, {1, { 9}}
// { 0, {0, { 3}}
//      {2, {15}} 
// { 1, {1, {20}}
// { 2, {2, { 7}}

// 12ms 22.42$ 16.3MB 30.94%
// 2 pass
// O(N) O(N)
class Solution {
 private:
  // {x : {y : {a,..}}}
  std::map<int, std::map<int, std::set<int>>> m_smp;
  void dfs(TreeNode *u, int x, int y) {
    // base
    if (!u)
      return;

    // recursion
    m_smp[x][y].insert(u->val);
    dfs(u->left, x - 1, y + 1);
    dfs(u->right, x + 1, y + 1);
  }
 public:
  std::vector<std::vector<int>> verticalTraversal(TreeNode* u) {
    std::vector<std::vector<int>> ans;
    dfs(u, 0, 0);
    for (auto itx = m_smp.begin(); itx != m_smp.end(); ++itx) {
      ans.push_back({});
      for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
        ans.back().insert(ans.back().end(), ity->second.begin(), ity->second.end());
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
