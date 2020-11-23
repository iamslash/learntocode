#include <cstdio>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
 private:
  TreeNode* prev;
 public:
  void dfs(TreeNode* u) {
    // base
    if (!u)
      return;
    // recursion
    inorder(u->left);
    if (prev) {
      printf("(%d) %d ", prev->val, u->val);
      if (prev->val < u->val)
        prev = u;
    } else {
      printf("(N) %d ", u->val);
    }
    inorder(u->right);
  }
  void inorder(TreeNode* u) {
    prev = u;
    dfs(u);
  }
};


 //     4
 //    / \
 //   2   5
 //  / \
 // 1   3

int main() {
  TreeNode* u = new TreeNode(4,
                             new TreeNode(2,
                                          new TreeNode(1),
                                          new TreeNode(3)),
                             new TreeNode(5));
  Solution sln;
  sln.inorder(u);
  return 0;
}
