/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 168ms 85.37% 40MB 8.13%
// DFS
// O(N) O(N)
class Solution {
 private:
  int dfs(Node* u) {
    if (u->val == '+')
      return dfs(u->left) + dfs(u->right);
    return (u->val - '`') * (u->val - '`');
  }
 public:
  bool checkEquivalence(Node* root1, Node* root2) {
    return dfs(root1) == dfs(root2);
  }
};

// 164ms 95.12% 40.2MB 8.13%
// DFS
// O(N) O(N)
class Solution {
 private:
  void dfs(Node* u, char last, vector<int>& ctx) {
    // base
    if (!u->left && !u->right) {
      if (last == '+') {
        ctx[u->val - 'a']++;
      } else {
        ctx[u->val - 'a']--;
      }
      return;
    }
    // recursion
    dfs(u->left, u->val, ctx);
    dfs(u->right, u->val, ctx);
  }
 public:
  bool checkEquivalence(Node* root1, Node* root2) {
    vector<int> ctx1(26);
    vector<int> ctx2(26);
    dfs(root1, '+', ctx1);
    dfs(root2, '+', ctx2);
    return equal(ctx1.begin(), ctx1.end(), ctx2.begin());
  }
};
