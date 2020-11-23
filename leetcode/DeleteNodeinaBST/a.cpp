/* Copyright (C) 2018 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

// 32ms 44.64%
class Solution {
 private:
  TreeNode* getMinNode(TreeNode* t) {
    TreeNode* r = t;
    while (r->left != NULL)
      r = r->left;
    return r;
  }
 public:
  TreeNode* deleteNode(TreeNode* t, int key) {
    if (t == NULL)
      return NULL;
    if (t->val < key) {
      t->right = deleteNode(t->right, key);
    } else if (t->val > key) {
      t->left = deleteNode(t->left, key);
    } else {
      if (t->left == NULL) {
        TreeNode* u = t->right;
        delete t;
        return u;
      } else if (t->right == NULL) {
        TreeNode* u = t->left;
        delete t;
        return u;
      }
      TreeNode* u = getMinNode(t->right);
      t->val = u->val;
      t->right = deleteNode(t->right, u->val);
    }
    return t;
  }
};

void printt(TreeNode* t) {
  if (t) {
    printf("%d ", t->val);
    printt(t->left);
    printt(t->right);
  } else {
    printf("N ");
  }
}

int main() {
  TreeNode* t = new TreeNode(
      5,
      new TreeNode(
          3,
          new TreeNode(2),
          new TreeNode(4)),
      new TreeNode(
          6, NULL,
          new TreeNode(7)));
  Solution sln;
  t = sln.deleteNode(t, 3);
  printt(t);
  printf("\n");
  return 0;
}
