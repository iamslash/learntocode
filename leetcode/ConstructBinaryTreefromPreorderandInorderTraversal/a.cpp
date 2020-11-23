// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/788/

#include <cstdio>
#include <vector>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int v) : val(v), left(NULL), right(NULL) {}
  // explicit TreeNode(int v, TreeNode* l, TreeNode* r) :
  //     val(v), left(l), right(r) {}
};

//             p
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//              i
  //   3
  //  / \
  // 9  20
  //   /  \
  //  15   7

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& pre, std::vector<int>& ino) {
    // base condition
    if (pre.size() == 0)
      return NULL;

    // job
    auto it_pre = pre.begin();
    int val = *it_pre;
    auto it_ino = std::find(ino.begin(), ino.end(), val);
    TreeNode* node = new TreeNode(val);
    int cntl = it_ino - ino.begin();
    int cntr = std::max(0, (int)(ino.end() - it_ino - 1));
    it_pre++;
    // printf("%d %d %d\n", val, cntl, cntr);
    
    // recursion
    if (cntl > 0) {
      std::vector<int> p(it_pre, it_pre+cntl);
      std::vector<int> i(ino.begin(), ino.begin()+cntl);
      // printf(" %d %d\n", p.size(), i.size());
      node->left = buildTree(p, i);
    }
    if (cntr > 0) {
      std::vector<int> p(it_pre+cntl, pre.end());
      std::vector<int> i(ino.begin()+cntl+1, ino.end());
      // printf(" %d %d\n", p.size(), i.size());
      node->right = buildTree(p, i);
    }
    return node;
  }
};

// print preorder traversal
void dump(TreeNode* r) {
  // base condition
  if (r == NULL)
    return;

  // task
  printf("%d ", r->val);

  // recursion
  if (r->left) dump(r->left);
  if (r->right) dump(r->right);  
}

int main() {
  std::vector<int> a = {3, 9, 20, 15, 7};
  std::vector<int> b = {9, 3, 15, 20, 7};

  Solution s;
  TreeNode* r = s.buildTree(a, b);

  dump(r);
  printf("\n");
  return 0;
}
