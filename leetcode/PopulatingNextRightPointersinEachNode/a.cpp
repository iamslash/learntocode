// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37578/My-simple-non-iterative-C++-code-with-O(1)-memory

#include <cstdio>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  explicit TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  explicit TreeLinkNode(int x, TreeLinkNode* l, TreeLinkNode* r) :
      val(x), left(l), right(r), next(NULL) {}
};

//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7

// BFS
class Solution {
 public:
    void connect(TreeLinkNode *root) {
      if (root == NULL)
        return;
      while (root->left) {
        TreeLinkNode* p = root;
        while (p) {
          p->left->next = p->right;
          if (p->next)
            p->right->next = p->next->left;
          p = p->next;
        }
        root = root->left;
      }
    }
};

int main() {
  return 0;
}
