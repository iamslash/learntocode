// Copyright (C) 2018 by iamslash

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

#include <cstdio>

class Node {
 public:  
  int val;
  Node* left;
  Node* right;
  Node(int _val, Node* _left, Node* _right) :
      val(_val), left(_left), right(_right) {}
};

Node * LCA(Node* root, int lv, int rv) {
  // base condition
  if (root == NULL)
    return NULL;
  if (root->val == lv || root->val == rv)
    return root;

  // recursion
  Node* left_lca = LCA(root->left, lv, rv);
  Node* right_lca = LCA(root->right, lv, rv);

  if (left_lca && right_lca)
    return root;
  
  return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
  Node * root = new Node( 1, new Node(2,
                                      new Node(4, NULL, NULL),
                                      new Node(5, NULL, NULL)),
                             new Node(3,
                                      new Node(6, NULL, NULL),
                                      new Node(7, NULL, NULL)));
  printf("%d\n", LCA(root, 4, 5)->val); // 2
  printf("%d\n", LCA(root, 4, 6)->val); // 1
  printf("%d\n", LCA(root, 3, 4)->val); // 1
  printf("%d\n", LCA(root, 2, 4)->val); // 2
  return 0;
}
