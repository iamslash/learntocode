/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

#include <cstdio>
#include <vector>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

//   p
// 9 3 15 20 7
// 9 15 7 20 3
//
//   3
//  / \
// 9  20
//   /  \
//  15   7

// O(N) O(N)
// 12ms 75.71%
class Solution {
 public:
  TreeNode* solve(const std::vector<int>& in, int is, int ie,
                  const std::vector<int>& po, int ps, int pe) {
    // base condition
    if (ps > pe)
      return NULL;
    TreeNode* p = new TreeNode(po[pe]);
    // int pos = std::find(in.begin() + is, in.begin() + ie + 1, p->val) -
    //     (in.begin() + is);
    int pos = 0;
    for (int i = is; i <= ie; ++i) {
      if (in[i] == p->val) {
        pos = i;
        break;
      }
    }
    p->left  = solve(in, is, pos-1, po, ps, ps + (pos - is - 1));
    p->right = solve(in, pos+1, ie, po, pe - (ie - pos) , pe-1);
    return p;
  }
  TreeNode* buildTree(std::vector<int>& in, std::vector<int>& po) {
    return solve(in, 0, in.size()-1, po, 0, po.size()-1);
  }
};

void printt(TreeNode* r) {
  if (r == NULL) {
    printf("N ");
    return;
  }
  printt(r->left);
  printf("%d ", r->val);
  printt(r->right);
}

int main() {
  std::vector<int> in = {9,3,15,20,7};
  std::vector<int> po = {9,15,7,20,3};

  Solution s;
  TreeNode* r = s.buildTree(in, po);
  printt(r);
    
  return 0;
}
