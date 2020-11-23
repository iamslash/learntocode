/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4 2
// i
//   j
//     k

// // 8ms 45.95% 10.9MB 57.06%
// // DFS
// // O(N) O(lgN)
// class Solution {
//  private:
//   TreeNode* dfs(std::vector<int>& P, int i, int j) {
//     // base
//     if (i > j)
//       return NULL;
//     TreeNode* r = new TreeNode(P[i]);
//     int k = i;
//     while (k <= j && P[k] <= P[i])
//       ++k;

//     // recursion
//     if (i < j && P[i] >= P[i+1])
//       r->left = dfs(P, i+1, k-1);
//     if (i < j && k <= j && P[i] < P[k])
//       r->right = dfs(P, k, j);
//     return r;
//   }
//  public:
//   TreeNode* bstFromPreorder(std::vector<int>& P) {
//     return dfs(P, 0, P.size()-1);
//   }
// };

//     5
//    / \
//   3   8

// 4ms 86.98% 10.8MB 75.00%
// DFS
// O(N) O(lgN)
class Solution {
 private:
  // bnd : bound value
  TreeNode* dfs(std::vector<int> &P, int& idx, int bnd) {
    if (idx >= P.size() || P[idx] > bnd)
      return NULL;
    TreeNode *r = new TreeNode(P[idx++]);
    r->left = dfs(P, idx, r->val);
    r->right = dfs(P, idx, bnd);
    return r;
  }
 public:
  TreeNode* bstFromPreorder(std::vector<int> &P) {
    int idx = 0;
    return dfs(P, idx, INT_MAX);
  }
};

int main() {
  return 0;
}
