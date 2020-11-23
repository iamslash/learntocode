// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/all-possible-full-binary-trees/description/

#include <cstdio>
#include <vector>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

//       0
//      / \
//     0   0
//    / \
//   0   0
//
//       0
//      / \
//     0   0
//        / \
//       0   0
class Solution {
 public:
  std::unordered_map<int, std::vector<TreeNode*>> m_C;
  std::vector<TreeNode*> allPossibleFBT(int N) {
    std::vector<TreeNode*> res;

    // base condition
    if (N < 1 || N % 2 == 0) {
      return res;
    }
    if (N == 1) {
      res.push_back(new TreeNode(0));
      return res;
    }
    // memoization
    if (m_C.count(N) > 0)
      return m_C[N];

    // recursion
    for (int i = 1; i < N; i += 2) {
      std::vector<TreeNode*> l = allPossibleFBT(i);
      std::vector<TreeNode*> r = allPossibleFBT(N-1-i);
      // printf("%d %lu %lu\n", N, l.size(), r.size());

      for (int j = 0; j < l.size(); ++j) {
        for (int k = 0; k < r.size(); ++k) {
          // printf("%lu %lu %d %d\n", l.size(), r.size(), j, k);
          res.push_back(new TreeNode(0));
          res.back()->left = l[j];
          res.back()->right = r[k];
        }
      }
    }
    return m_C[N] = res;
  }
};

int main() {
  Solution s;
  auto r = s.allPossibleFBT(3);
  return 0;
}
