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
 public:
  void postorder(TreeNode* u) {
    // base
    if (!u)
      return;
    // recursion
    postorder(u->left);
    postorder(u->right);
    printf("%d ", u->val);
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
  sln.postorder(u);
  return 0;
}
