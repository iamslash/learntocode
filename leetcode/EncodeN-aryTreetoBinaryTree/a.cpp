/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// Definition for a Node.
class Node {
 public:
  int val = 0;
  std::vector<Node*> children;
  Node() {}
  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 240ms 92.11% 48.8MB 80.00%
class Codec {
 public:

  // Encodes an n-ary tree to a binary tree.
  TreeNode* encode(Node* u) {
    // base
    if (u == NULL)
      return NULL;
    TreeNode* v = new TreeNode(u->val);
    if (u->children.size() == 0)
      return v;
    v->left = encode(u->children[0]);
    TreeNode* p = v->left;
    for (int i = 1; i < u->children.size(); ++i) {
      p->right = encode(u->children[i]);
      p = p->right;
    }
    return v;
  }

  // Decodes your binary tree to an n-ary tree.
  Node* decode(TreeNode* u) {
    // base
    if (u == NULL)
      return NULL;
    Node* v = new Node();
    v->val = u->val;
    TreeNode* p = u->left;
    while (p) {
      v->children.push_back(decode(p));
      p = p->right;
    }
    return v;
  }
};

int main() {
  return 0;
}
