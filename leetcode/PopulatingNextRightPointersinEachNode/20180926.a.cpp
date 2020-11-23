/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/789/

#include <cstdio>
#include <queue>
#include <cmath>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  TreeLinkNode(int x, TreeLinkNode* l, TreeLinkNode* r) {
    val = x;
    left = l;
    right = r;
    next = NULL;    
  }
};

class Solution {
 public:
  void connect(TreeLinkNode *root) {
    // check empty root
    if (root == NULL)
      return;

    // BFS
    int lv = 1;
    int n = 1;
    std::queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeLinkNode* p = q.front(); q.pop();
      if (q.size() > 0) {
        p->next = q.front();
      }
      // check lv
      if (n == std::pow(2, lv) - 1) {
        p->next = NULL;
        lv++;
      }
      // check n
      n++;
      // push children
      if (p->left)
        q.push(p->left);
      if (p->right)
        q.push(p->right);

      // // print
      // if (p->next)
      //   printf("%d ", p->next->val);
      // else
      //   printf("NULL "); 
    }
  }
};

int main() {
  TreeLinkNode* root = new TreeLinkNode(1,
                                        new TreeLinkNode(2,
                                                         new TreeLinkNode(4),
                                                         new TreeLinkNode(5)),
                                        new TreeLinkNode(3,
                                                         new TreeLinkNode(6),
                                                         new TreeLinkNode(7)));  
  Solution s;
  s.connect(root);
  return 0;
}
