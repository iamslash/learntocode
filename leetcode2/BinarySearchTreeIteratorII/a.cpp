/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 688ms 73.26% 150MB 83.72%
// stack
class BSTIterator {
 private:
  stack<TreeNode*> stck;
  vector<int> vals;
  int pos = -1;
  void traverseLeft(TreeNode* u) {
    while (u) {
      stck.push(u);
      u = u->left;
    }
  }
 public:
  BSTIterator(TreeNode* u) {
    traverseLeft(u);
  }
    
  bool hasNext() {
    return pos + 1 < vals.size() || !stck.empty();        
  }
    
  int next() {
    if (++pos == vals.size()) {
      TreeNode* cur = stck.top(); stck.pop();
      traverseLeft(cur->right);
      vals.push_back(cur->val);
    }
    return vals[pos];
  }
    
  bool hasPrev() {
    return pos > 0;
  }
    
  int prev() {
    return vals[--pos];
  }
};
