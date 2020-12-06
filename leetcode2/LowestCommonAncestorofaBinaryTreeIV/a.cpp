/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// 6 5 7 2 4 3 0 1 8

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 192ms 7.56 46.3MB 27.73%
// DFS
class Solution {
 private:
  TreeNode* lca = nullptr;
  int dfs(TreeNode* u, unordered_set<TreeNode*>& path) {
    // base
    if (!u) {
      return 0;
    }
    // recursion
    int matched = path.count(u) +
        dfs(u->left, path) +
        dfs(u->right, path);
    if (matched == path.size() && lca == nullptr) {
      lca = u;
    }
    return matched;
  }
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    unordered_set<TreeNode*> path(nodes.begin(), nodes.end());
    dfs(root, path);
    return lca;
  }
};

// 100ms 100.00% 42.4MB 98.32%
// DFS
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* u, vector<TreeNode*> &nodes) {
    // base
    if (!u) {
      return NULL;
    }
    for (TreeNode* v : nodes) {
      if (v->val == u->val) {
        return u;
      }
    }
    // recursion
    TreeNode* l = lowestCommonAncestor(u->left, nodes);
    TreeNode* r = lowestCommonAncestor(u->right, nodes);
    if (l && r) {
      return u;
    }
    return l ? l : r;
  }
};
