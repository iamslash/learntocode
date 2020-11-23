/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//      i
// pre: 1
// pst: 1
//        j

//            i
// pre: 1 2 4 5 3 6 7
// pst: 4 5 2 6 7 3 1
//        j
//   V: 1 2 4

// 8ms 94.24% 9.4MB 96.91%
// O(N) O(N)
class Solution {
 public:
  TreeNode* constructFromPrePost(std::vector<int>& pre, std::vector<int>& pst) {
    std::vector<TreeNode*> V;
    V.push_back(new TreeNode(pre[0]));
    for (int i = 1, j = 0; i < pre.size(); ++i) {
      TreeNode* u = new TreeNode(pre[i]);
      while (V.back()->val == pst[j]) {
        V.pop_back();
        ++j;
      }
      if (V.back()->left == NULL)
        V.back()->left = u;
      else
        V.back()->right = u;
      V.push_back(u);
    }
    return V[0];
  }
};

int main() {
  return 0;
}
