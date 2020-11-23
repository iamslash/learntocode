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
 private:
  void pushLeft(std::stack<TreeNode*>& stck, TreeNode* p) {
    while (p) {
      stck.push(p);
      p = p->left;
    }
  }
 public:
  void inorder(TreeNode* u) {
    std::stack<TreeNode*> stck;
    // insert most left nodes
    pushLeft(stck, u);
    // loop
    while (stck.size()) {
      TreeNode* u = stck.top(); stck.pop();
      printf("%d ", u->val);
      pushLeft(stck, u->right);
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
  sln.inorder(u);
  return 0;
}
