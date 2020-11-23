/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

void printt(TreeNode* t) {
  if (t == NULL)
    return;
  printf("%d ", t->val);
  printt(t->left);
  printt(t->right);
}

class Solution {
 private:
  TreeNode* solve(const std::vector<int>& pr,
                  const std::vector<int>& po,
                  int pr_idx, int pr_cnt,
                  int po_idx, int po_cnt) {
    // base
    if (pr_e < pr_s)
      return NULL;
    TreeNode* t = new TreeNode(pr[pr_idx]);

    // recursion
    
    l_pr_idx = pr_idx + 1;
    l_pr_cnt = 0;
    l_po_idx = pr_idx;
    l_po_cnt = l_pr_cnt;
    
    r_pr_idx = l_pr_idx + l_pr_cnt;
    r_pr_cnt = 0;
    r_po_idx = pr_idx + 1;
    r_po_cnt = 0;
    
    pr_cnt = std::find(pr.begin());
    
    
    t->left = solve(pr, po, l_pr_idx, l_pr_cnt, l_po_idx, l_po_cnt);
    t->right = solve(pr, po, r_pr_idx, r_pr_cnt, r_po_idx, r_po_cnt);

    return t;
  }  
 public:
  TreeNode* constructFromPrePost(const std::vector<int>& pr,
                                 const std::vector<int>& po) {
    return solve(pr, po, 0, pr.size(), 0, po.size());    
  }
};

int main() {

  std::vector<int> pr = {1, 2, 4, 5, 3, 6, 7};
  std::vector<int> po = {4, 5, 2, 6, 7, 3, 1};

  Solution sln;
  TreeNode* t = sln.constructFromPrePost(pr, po);
  
  return 0;
}
