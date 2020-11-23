/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 24ms 72.67% 23MB 100.00%
// inOrder
// O(N) O(N)
class Solution {
 private:
  int curMod = std::numeric_limits<int>::min();
  int curCnt = 0;
  int modCnt = 0;
  int maxCnt = 0;
  void handle(int v, std::vector<int>* modes) {
    if (v != curMod) {
      curMod = v;
      curCnt = 0;
    }
    curCnt++;
    if (curCnt > maxCnt) {
      maxCnt = curCnt;
      modCnt = 1;
    } else if (curCnt == maxCnt) {
      if (modes) {
        (*modes)[modCnt] = curMod;
      }
      modCnt++;
    }
  }
  void inOrder(TreeNode* u, std::vector<int>* modes) {
    // base
    if (!u)
      return;
    // recursion
    inOrder(u->left, modes);
    handle(u->val, modes);
    inOrder(u->right, modes);
  }
 public:
  std::vector<int> findMode(TreeNode* u) {
    inOrder(u, nullptr);
    auto modes = std::vector<int>(modCnt);
    curMod = std::numeric_limits<int>::min();
    curCnt = 0;
    modCnt = 0;
    inOrder(u, &modes);
    return modes;
  }
};

int main() {
  return 0;
}
