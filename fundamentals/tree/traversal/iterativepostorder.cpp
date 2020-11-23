#include <cstdio>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

class Solution {
 public:
  void postorder(TreeNode* u) {
    std::stack<TreeNode*> stck;
    stck.push(u);
    while (!stck.empty()) {
      TreeNode* u = stck.top(); stck.pop();
      if (u->left == NULL && u->right == NULL) {
        printf("%d ", u->val);
        continue;
      }
      stck.push(u);
      if (u->right) {
        stck.push(u->right);
        u->right = NULL;
      }
      if (u->left) {
        stck.push(u->left);
        u->left = NULL;
      }
    }
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
