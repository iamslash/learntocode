/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <queue>


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};
// 12ms 100.00%
class CBTInserter {
 private:
  TreeNode* m_root;
  std::queue<TreeNode*> m_q;
 public:
  CBTInserter(TreeNode* root) {
    m_root = root;
    m_q.push(root);
  }
    
  int insert(int val) {
    TreeNode* u = NULL;

    while (!u) {
      TreeNode* v = m_q.front();
      if (!v->left) {
        u = v;
        v->left = new TreeNode(val);
      } else if (!v->right) {
        u = v;
        v->right = new TreeNode(val);
      } else {
        m_q.pop();
        m_q.push(v->left);
        m_q.push(v->right);
      }
    }
    return u->val;
  }
    
  TreeNode* get_root() {
    return m_root;
  }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */

int main() {
  return 0;
}
