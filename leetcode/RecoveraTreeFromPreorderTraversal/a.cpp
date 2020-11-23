/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 20ms 93.09% 11.4MB 63.22%
// stack
// O(N) O(N)
class Solution {
 public:
  TreeNode* recoverFromPreorder(std::string s) {
    std::stack<TreeNode*> stck;
    TreeNode* r = NULL;
    int i = 0, n = s.size();
    while (i < n) {
      int lv = 0, val = 0;
      while (i < n && s[i] == '-') {
        lv++;
        i++;
      }
      while (i < n && s[i] != '-') {
        val = val * 10 + s[i++] - '0';
      }
      TreeNode* u = new TreeNode(val);
      if (r == NULL)
        r = u;
      while (stck.size() > lv)
        stck.pop();
      if (stck.size()) {
        if (stck.top()->left == NULL)
          stck.top()->left = u;
        else
          stck.top()->right = u;
      }
      stck.push(u);
    }
    return r;
  }
};

int main() {
  return 0;
}
