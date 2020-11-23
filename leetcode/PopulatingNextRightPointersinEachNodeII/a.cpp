// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

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
//  / \    \
// 4   5    7
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *p, *head, *tail;
    p = root;
    head = tail = NULL;
    while (p) {
      if (p->left) {
        if (tail) {
          tail = tail->next = p->left;
        } else {
          head = tail = p->left;
        }
      }
      if (p->right) {
        if (tail) {
          tail = tail->next = p->right;
        } else {
          head = tail = p->right;
        }
      }
      p = p->next;
      if (p == NULL) {
        p = head;
        head = tail = NULL;
      }
    }
  }
};

int main() {
  TreeLinkNode* r = new TreeLinkNode(1,
                                     new TreeLinkNode(2,
                                                      new TreeLinkNode(4),
                                                      new TreeLinkNode(5)),
                                     new TreeLinkNode(3,
                                                      NULL,
                                                      new TreeLinkNode(7)));
  Solution s;
  s.connect(r);
  return 0;
}
